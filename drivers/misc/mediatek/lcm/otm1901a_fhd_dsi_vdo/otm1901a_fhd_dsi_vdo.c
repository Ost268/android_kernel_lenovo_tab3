/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
#include "lcm_drv.h"
#ifndef BUILD_LK
#include <linux/string.h>
#include <linux/kernel.h>
#endif

#ifdef BUILD_LK
#include <platform/upmu_common.h>
#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <string.h>
#elif defined(BUILD_UBOOT)
#include <asm/arch/mt_gpio.h>
#else
#include "mt-plat/upmu_common.h"

#ifdef CONFIG_MTK_LEGACY
#include <mach/mt_pm_ldo.h>
#include <mach/mt_gpio.h>

#ifndef CONFIG_FPGA_EARLY_PORTING
#include <cust_gpio_usage.h>
#include <cust_i2c.h>
#endif

#endif
#endif

#define LOG_TAG "LCM"
#ifdef BUILD_LK
#define LCM_LOGI(string, args...)  dprintf(0, "[LK/"LOG_TAG"]"string, ##args)
#define LCM_LOGD(string, args...)  dprintf(1, "[LK/"LOG_TAG"]"string, ##args)
#else
#define LCM_LOGI(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#define LCM_LOGD(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif

#include <linux/string.h>
#include <linux/wait.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/pinctrl/consumer.h>
#include <linux/of_gpio.h>
#include <linux/gpio.h>
#include <asm-generic/gpio.h>

#include "lcm_drv.h"
#include "ddp_irq.h"

static unsigned int GPIO_LCD_PWR_EN;
static unsigned int GPIO_LCD_BL_EN;
#ifndef CONFIG_FPGA_EARLY_PORTING
#ifndef CONFIG_MTK_LEGACY
static unsigned int GPIO_LCD_BIAS_ENN, GPIO_LCD_BIAS_ENP;
#endif
#endif

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH  (1080)
#define FRAME_HEIGHT (1920)

//#define LCM_ID_OMT9608A ()

#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif

#define REGFLAG_DELAY             							0XFE
#define REGFLAG_END_OF_TABLE      							0XFD   // END OF REGISTERS MARKER

// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))


// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	        lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)											lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)   

#ifndef BUILD_LK
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/i2c.h>
#include <linux/irq.h>
/* #include <linux/jiffies.h> */
/* #include <linux/delay.h> */
#include <linux/uaccess.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/platform_device.h>

/*****************************************************************************
 * Define
 *****************************************************************************/
#ifndef CONFIG_FPGA_EARLY_PORTING

#define I2C_I2C_LCD_BIAS_CHANNEL 3
#define TPS_I2C_BUSNUM  I2C_I2C_LCD_BIAS_CHANNEL	/* for I2C channel 3 */
#define I2C_ID_NAME "tps65132"
#define TPS_ADDR 0x3E
/*****************************************************************************
 * GLobal Variable
 *****************************************************************************/
//static struct i2c_board_info tps65132_board_info __initdata = { I2C_BOARD_INFO(I2C_ID_NAME, TPS_ADDR) };

static struct i2c_client *tps65132_i2c_client;

/*****************************************************************************
 * Function Prototype
 *****************************************************************************/
static int tps65132_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int tps65132_remove(struct i2c_client *client);
/*****************************************************************************
 * Data Structure
 *****************************************************************************/

struct tps65132_dev {
	struct i2c_client *client;

};

static const struct i2c_device_id tps65132_id[] = {
	{I2C_ID_NAME, 0},
	{}
};

static const struct of_device_id lcd_i2c_bias_of_match[] = {
	{.compatible = "mediatek,i2c_lcd_bias"},
	{},
};
/* #if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,36)) */
/* static struct i2c_client_address_data addr_data = { .forces = forces,}; */
/* #endif */
static struct i2c_driver tps65132_iic_driver = {
	.id_table = tps65132_id,
	.probe = tps65132_probe,
	.remove = tps65132_remove,
	/* .detect               = mt6605_detect, */
	.driver = {
		   .owner = THIS_MODULE,
		   .name = "tps65132",
		   .of_match_table = lcd_i2c_bias_of_match,
		   },
};

static int tps65132_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	printk("tps65132_iic_probe\n");
	LCM_LOGI("TPS: info==>name=%s addr=0x%x\n", client->name, client->addr);
	tps65132_i2c_client = client;
	return 0;
}

static int tps65132_remove(struct i2c_client *client)
{
	LCM_LOGI("tps65132_remove\n");
	tps65132_i2c_client = NULL;
	i2c_unregister_device(client);
	return 0;
}

static int tps65132_write_bytes(unsigned char addr, unsigned char value)
{
	int ret = 0;
	struct i2c_client *client = tps65132_i2c_client;
	char write_data[2] = { 0 };

	if (!client)
	{
		pr_err("%s: client is NULL\n", __func__);
		return -1;
	}

	write_data[0] = addr;
	write_data[1] = value;
	ret = i2c_master_send(client, write_data, 2);
	if (ret < 0)
		LCM_LOGI("tps65132 write data fail !!\n");
	return ret;
}

static int __init tps65132_iic_init(void)
{
	LCM_LOGI("STT:tps65132_iic_init\n");
	//ret = i2c_register_board_info(TPS_I2C_BUSNUM, &tps65132_board_info, 1);
	LCM_LOGI("STT:tps65132_iic_init2\n");
	i2c_add_driver(&tps65132_iic_driver);
	LCM_LOGI("STT:tps65132_iic_init success\n");
	return 0;
}

static void __exit tps65132_iic_exit(void)
{
	LCM_LOGI("tps65132_iic_exit\n");
	i2c_del_driver(&tps65132_iic_driver);
}


module_init(tps65132_iic_init);
module_exit(tps65132_iic_exit);

MODULE_AUTHOR("Xiaokuan Shi");
MODULE_DESCRIPTION("MTK TPS65132 I2C Driver");
MODULE_LICENSE("GPL");
#endif
#endif


#define   LCM_DSI_CMD_MODE							0





struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};





static struct LCM_setting_table lcm_initialization_setting[] = {

	/*

	Note :

	Data ID will depends on the following rule.

		count of parameters > 1	=> Data ID = 0x39
		count of parameters = 1	=> Data ID = 0x15
		count of parameters = 0	=> Data ID = 0x05
		
	Structure Format :

	{DCS command, count of parameters, {parameter list}}
	{REGFLAG_DELAY, milliseconds of time, {}},
	...
	Setting ending by predefined flag
	{REGFLAG_END_OF_TABLE, 0x00, {}}

	*/
#if 1
	{0x00, 1 ,{0x00}},
	{0xFF, 3  ,{0x19,0x01,0x01}},

	{0x00, 1, {0x80}},
	{0xff, 2, {0x19,0x01}},

	{0x00, 1, {0x00}},
	{0x1c, 1, {0x33}},

	{0x00, 1, {0xa0}},
	{0xc1, 1, {0x00}},

	{0x35, 1, {0x00}},
	{0x51, 1, {0xff}},
	{0x53, 1, {0x2c}},
	{0x55, 1, {0x00}},

    {0x11, 0 ,{}},
    {REGFLAG_DELAY, 120, {}},
    
    {0x29, 0 ,{}},

    
    //{0x2C, 1 ,{0x00}}, 
    	// Note
    	// Strongly recommend not to set Sleep out / Display On here. That will cause messed frame to be shown as later the backlight is on.
    	// Setting ending by predefined flag
    
    {REGFLAG_END_OF_TABLE, 0x00, {}}
#else
    {0x00, 1 ,{0x00}}, 
    {0xFF, 4  ,{0x19,0x01,0x01,0x00}},

    {0x00, 1 ,{0x80}}, 
    {0xFF, 2  ,{0x19,0x01}},
    
    {0x00, 1 ,{0xDA}}, 
    {0xF5, 1  ,{0x21}},
    
    {0x00, 1 ,{0x00}}, 
    {0xFB, 1  ,{0x01}},
    
    {0x00, 1 ,{0x00}}, 
    {0xEB, 1  ,{0x10}},
    
    {0x00, 1 ,{0x02}}, 
    {0xff, 1  ,{0x03}},
    
    {0x00, 1 ,{0x00}}, 
    {0xc0, 1  ,{0x00}},
    
    {0x00, 1 ,{0x02}}, 
    {0xff, 1  ,{0x01}},
    
    {0x00, 1 ,{0xa0}}, 
    {0xc1, 1  ,{0xe8}},
    
    {0x00, 1 ,{0xa7}}, 
    {0xc1, 1  ,{0x00}},
    
    {0x00, 1 ,{0x90}}, 
    {0xc0, 6  ,{0x00,0x2F,0x00,0x00,0x00,0x01}},
    
    {0x00, 1 ,{0xC0}}, 
    {0xc0, 6  ,{0x00,0x2F,0x00,0x00,0x00,0x01}},
    
    {0x00, 1 ,{0x9a}}, 
    {0xc0, 1  ,{0x1e}},
    
    {0x00, 1 ,{0xac}}, 
    {0xc0, 1  ,{0x06}},
    
    {0x00, 1 ,{0xdc}}, 
    {0xc0, 1  ,{0x06}},
    
    {0x00, 1 ,{0x80}}, 
    {0xC0, 14  ,{0x00,0x7F,0x00,0x08,0x08,0x00,0x7F,0x08,0x08,0x00,0x7F,0x00,0x08,0x08}},
    
    {0x00, 1 ,{0xF0}}, 
    {0xC3, 6  ,{0x00,0x00,0x00,0x00,0x00,0x80}},
    
    {0x00, 1 ,{0xA0}}, 
    {0xC0, 7  ,{0x00,0x0A,0x00,0x00,0x00,0x1A,0x05}},
    
    {0x00, 1 ,{0xD0}},
    {0xC0, 7  ,{0x00,0x0A,0x00,0x00,0x00,0x1A,0x05}},
    
    {0x00, 1 ,{0x90}}, 
    {0xC2, 8  ,{0x83,0x01,0x78,0x61,0x83,0x01,0x78,0x61}},
    
    {0x00, 1 ,{0x80}},
    {0xC3, 12  ,{0x84,0x06,0x03,0x01,0x00,0x01,0x85,0x05,0x03,0x01,0x00,0x01}},
    
    {0x00, 1 ,{0x90}}, 
    {0xC3, 12  ,{0x82,0x08,0x03,0x01,0x00,0x01,0x83,0x03,0x03,0x01,0x00,0x01}},
    
    {0x00, 1 ,{0x80}}, 
    {0xCC, 15  ,{0x09,0x0A,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x28,0x28,0x28,0x28,0x28}},
    
    {0x00, 1 ,{0x90}}, 
    {0xCC, 15  ,{0x09,0x0A,0x14,0x13,0x12,0x11,0x18,0x17,0x16,0x15,0x28,0x28,0x28,0x28,0x28}},
    
    {0x00, 1 ,{0xA0}}, 
    {0xCC, 15  ,{0x1D,0x1E,0x1F,0x19,0x1A,0x1B,0x1C,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27}},
    
    {0x00, 1 ,{0xB0}}, 
    {0xCC, 8 ,{0x01,0x02,0x03,0x05,0x06,0x07,0x04,0x08}},
    
    {0x00, 1 ,{0xC0}}, 
    {0xCC, 12 ,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x66}},
    
    {0x00, 1 ,{0xD0}}, 
    {0xCC, 12 ,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x02,0x00,0x66}},
    
    {0x00, 1 ,{0xDE}}, 
    {0xCC, 1 ,{0x00}},
    
    {0x00, 1 ,{0x80}}, 
    {0xCB, 15 ,{0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
    
    {0x00, 1 ,{0x90}}, 
    {0xCB, 15 ,{0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
    
    {0x00, 1 ,{0xA0}}, 
    {0xCB, 15 ,{0x01,0x00,0xFD,0xFD,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
    
    {0x00, 1 ,{0xB0}}, 
    {0xCB, 15 ,{0x00,0x01,0xFD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
    
    {0x00, 1 ,{0xC0}}, 
    {0xCB, 8 ,{0x00,0x00,0x00,0x22,0x22,0x22,0x66,0x66}},
    
    {0x00, 1 ,{0xD0}}, 
    {0xCB, 8 ,{0x00,0x00,0x00,0x00,0x00,0x00,0x66,0x66}},
    
    {0x00, 1 ,{0xE0}}, 
    {0xCB, 8 ,{0x00,0x00,0x00,0x00,0x00,0x00,0x66,0x00}},
    
    {0x00, 1 ,{0xF0}}, 
    {0xCB, 8 ,{0x01,0x01,0x01,0x01,0x01,0x01,0x66,0x66}},
    
    {0x00, 1 ,{0x80}}, 
    {0xCD, 15 ,{0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x01,0x12,0x11,0x04,0x06,0x3F,0x3C}},
    
    {0x00, 1 ,{0x90}}, 
    {0xCD, 11 ,{0x3F,0x3F,0x3D,0x25,0x25,0x25,0x1F,0x20,0x21,0x25,0x25}},
    
    {0x00, 1 ,{0xA0}},
    {0xCD, 15 ,{0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x01,0x12,0x11,0x03,0x05,0x3F,0x3C}},
    
    {0x00, 1 ,{0xB0}}, 
    {0xCD, 11 ,{0x3F,0x3F,0x3D,0x25,0x25,0x25,0x1F,0x20,0x21,0x25,0x25}},
    
    {0x00, 1 ,{0x00}}, 
    {0xE1, 24 ,{0x00,0x10,0x19,0x24,0x2d,0x33,0x40,0x53,0x61,0x74,0x81,0x8a,0x6f,0x69,0x65,0x58,0x47,0x38,0x2b,0x25,0x1d,0x15,0x10,0x00}},
    {0x00, 1 ,{0x00}},
    
    {0x00, 1 ,{0x00}}, 
    {0xE2, 24 ,{0x00,0x10,0x19,0x24,0x2d,0x33,0x40,0x53,0x61,0x74,0x81,0x8a,0x6f,0x69,0x65,0x58,0x47,0x38,0x2b,0x25,0x1d,0x15,0x10,0x00}},
    {0x00, 1 ,{0x00}},
    
    {0x00, 1 ,{0x00}}, 
    {0xE3, 24 ,{0x00,0x10,0x19,0x24,0x2d,0x33,0x40,0x53,0x61,0x74,0x81,0x8a,0x6f,0x69,0x65,0x58,0x47,0x38,0x2b,0x25,0x1d,0x15,0x10,0x00}},
    {0x00, 1 ,{0x00}},
    
    {0x00, 1 ,{0x00}}, 
    {0xE4, 24 ,{0x00,0x10,0x19,0x24,0x2d,0x33,0x40,0x53,0x61,0x74,0x81,0x8a,0x6f,0x69,0x65,0x58,0x47,0x38,0x2b,0x25,0x1d,0x15,0x10,0x00}},
    {0x00, 1 ,{0x00}},
    
    {0x00, 1 ,{0x00}}, 
    {0xE5, 24 ,{0x00,0x10,0x19,0x24,0x2d,0x33,0x40,0x53,0x61,0x74,0x81,0x8a,0x6f,0x69,0x65,0x58,0x47,0x38,0x2b,0x25,0x1d,0x15,0x10,0x00}},
    {0x00, 1 ,{0x00}},
    
    {0x00, 1 ,{0x00}}, 
    {0xE6, 24 ,{0x00,0x10,0x19,0x24,0x2d,0x33,0x40,0x53,0x61,0x74,0x81,0x8a,0x6f,0x69,0x65,0x58,0x47,0x38,0x2b,0x25,0x1d,0x15,0x10,0x00}},
    {0x00, 1 ,{0x00}},
    
    {0x00, 1 ,{0xa4}}, 
    {0xf3, 1 ,{0x01}},
    
    {0x00, 1 ,{0x00}}, 
    {0x1c, 1 ,{0x33}},
    
    {0x11, 0 ,{}},
    {REGFLAG_DELAY, 12, {}},
    
    {0x29, 0 ,{}},

    
    //{0x2C, 1 ,{0x00}}, 
    	// Note
    	// Strongly recommend not to set Sleep out / Display On here. That will cause messed frame to be shown as later the backlight is on.
    	// Setting ending by predefined flag
    
    {REGFLAG_END_OF_TABLE, 0x00, {}}
#endif
};
/*
static struct LCM_setting_table lcm_sleep_out_setting[] = {
        // Sleep Out
	{0x11, 0, {}},
        {REGFLAG_DELAY, 120, {}},

        // Display ON
	{0x29, 0, {}},
	{REGFLAG_DELAY, 5, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};
*/



static struct LCM_setting_table lcm_sleep_mode_in_setting[] = {

	// Display off sequence
	{0x28, 0, {}},
	//{REGFLAG_DELAY, 200, {}},

        // Sleep Mode On

	{0x10, 0, {}},
	{REGFLAG_DELAY, 120, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}

};


void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)

{
	unsigned int i;

    for(i = 0; i < count; i++){ 
        unsigned cmd;
        cmd = table[i].cmd;

        switch (cmd) {
            case REGFLAG_DELAY :
                MDELAY(table[i].count);
                break;

            case REGFLAG_END_OF_TABLE :
                break;

            default:
		dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
		MDELAY(2);
       	}
    }
}

// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------
void lcm_get_gpio_infor(void)
{
	static struct device_node *node;

	node = of_find_compatible_node(NULL, NULL, "mediatek,mt6735-dispsys");

	GPIO_LCD_PWR_EN = of_get_named_gpio(node, "lcm_power_gpio", 0);
	GPIO_LCD_BL_EN = of_get_named_gpio(node, "lcm_bl_gpio", 0);
#ifndef CONFIG_FPGA_EARLY_PORTING
#ifndef CONFIG_MTK_LEGACY
	GPIO_LCD_BIAS_ENN = of_get_named_gpio(node, "lcm_bias_enn_gpio", 0);
	GPIO_LCD_BIAS_ENP = of_get_named_gpio(node, "lcm_bias_enp_gpio", 0);
#endif
#endif
}

static void lcm_set_gpio_output(unsigned int GPIO, unsigned int output)
{
	gpio_direction_output(GPIO, output);
	gpio_set_value(GPIO, output);
}

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}



static void lcm_get_params(LCM_PARAMS *params)
{
		memset(params, 0, sizeof(LCM_PARAMS));
	
		params->type   = LCM_TYPE_DSI;

		params->width  = FRAME_WIDTH;
		params->height = FRAME_HEIGHT;

       //1 SSD2075 has no TE Pin 
		// enable tearing-free
		//params->dbi.te_mode 				= LCM_DBI_TE_MODE_DISABLED;//LCM_DBI_TE_MODE_DISABLED;
		//params->dbi.te_edge_polarity		= LCM_POLARITY_RISING;

        #if (LCM_DSI_CMD_MODE)
		params->dsi.mode   = CMD_MODE;
        #else
		//params->dsi.mode   = SYNC_PULSE_VDO_MODE;
		params->dsi.mode   = BURST_VDO_MODE;
		//params->dsi.mode   = SYNC_EVENT_VDO_MODE; 
		
        #endif
	
		// DSI
		/* Command mode setting */
		//1 Three lane or Four lane
		params->dsi.LANE_NUM		    = LCM_FOUR_LANE;
		//The following defined the fomat for data coming from LCD engine.
		//params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
		//params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
		//params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
		params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

		// Highly depends on LCD driver capability.
		// Not support in MT6573
		//params->dsi.packet_size=256;

		// Video mode setting		
            //params->dsi.intermediat_buffer_num = 0;//because DSI/DPI HW design change, this parameters should be 0 when video mode in MT658X; or memory leakage

		params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
		//params->dsi.word_count=720*3;	

		
		params->dsi.vertical_sync_active				= 4;//1;  //---3
		params->dsi.vertical_backporch					= 15;//9; //---14
		params->dsi.vertical_frontporch					= 16;//8;  //----8
		params->dsi.vertical_active_line				= FRAME_HEIGHT; //1920

		params->dsi.horizontal_sync_active				= 4;  //----2
		params->dsi.horizontal_backporch				= 32; //----28
		params->dsi.horizontal_frontporch				= 32; //----50
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;//1080


        //	params->dsi.HS_PRPR=6;
	    //params->dsi.LPX=8; 
		//params->dsi.HS_PRPR=5;
		//params->dsi.HS_TRAIL=13;

		// Bit rate calculation
		//1 Every lane speed
		//params->dsi.pll_div1=1;		// div1=0,1,2,3;div1_real=1,2,4,4 ----0: 546Mbps  1:273Mbps
		//params->dsi.pll_div2=1;		// div2=0,1,2,3;div1_real=1,2,4,4	
		//params->dsi.fbk_div =30;//30;    // fref=26MHz, fvco=fref*(fbk_div+1)*2/(div1_real*div2_real)	

                 params->dsi.PLL_CLOCK=401;
#if 0
params->dsi.HS_TRAIL    = 10;//10;//min max(n*8*UI, 60ns+n*4UI)
params->dsi.HS_ZERO    = 10;//8;//min 105ns+6*UI
params->dsi.HS_PRPR    = 6;//min 40ns+4*UI; max 85ns+6UI
params->dsi.LPX    = 12;//min 50ns

params->dsi.TA_SACK=1;
params->dsi.TA_GET=60;
params->dsi.TA_SURE=18;  
params->dsi.TA_GO    = 12;//12;//4*LPX
//
params->dsi.CLK_TRAIL   = 5;//5;//min 60ns
params->dsi.CLK_ZERO    = 18;//18;//min 300ns-38ns
params->dsi.LPX_WAIT    = 10;
params->dsi.CONT_DET    = 0;

params->dsi.CLK_HS_PRPR = 4;//min 38ns; max 95ns 
#endif
		
}

#ifdef BUILD_LK
#ifndef CONFIG_FPGA_EARLY_PORTING
#define TPS65132_SLAVE_ADDR_WRITE  0x7C
static struct mt_i2c_t TPS65132_i2c;

static int TPS65132_write_byte(kal_uint8 addr, kal_uint8 value)
{
	kal_uint32 ret_code = I2C_OK;
	kal_uint8 write_data[2];
	kal_uint16 len;

	write_data[0] = addr;
	write_data[1] = value;

	TPS65132_i2c.id = I2C_I2C_LCD_BIAS_CHANNEL;	/* I2C3; */
	/* Since i2c will left shift 1 bit, we need to set FAN5405 I2C address to >>1 */
	TPS65132_i2c.addr = (TPS65132_SLAVE_ADDR_WRITE >> 1);
	TPS65132_i2c.mode = ST_MODE;
	TPS65132_i2c.speed = 100;
	len = 2;

	ret_code = i2c_write(&TPS65132_i2c, write_data, len);
	/* printf("%s: i2c_write: ret_code: %d\n", __func__, ret_code); */

	return ret_code;
}

#else

/* extern int mt8193_i2c_write(u16 addr, u32 data); */
/* extern int mt8193_i2c_read(u16 addr, u32 *data); */

/* #define TPS65132_write_byte(add, data)  mt8193_i2c_write(add, data) */
	/* #define TPS65132_read_byte(add)  mt8193_i2c_read(add) */

#endif
#endif


static void lcm_init(void)
{
	unsigned char cmd = 0x0;
	unsigned char data = 0xFF;
#ifndef CONFIG_FPGA_EARLY_PORTING
	int ret = 0;
#endif

	lcm_get_gpio_infor();
	lcm_set_gpio_output(GPIO_LCD_PWR_EN, 1);

	cmd = 0x00;
	data = 0x0E;
#ifndef CONFIG_FPGA_EARLY_PORTING
#ifdef CONFIG_MTK_LEGACY
	mt_set_gpio_mode(GPIO_65132_EN, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_65132_EN, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_65132_EN, GPIO_OUT_ONE);
#else
	lcm_set_gpio_output(GPIO_LCD_BIAS_ENN, 1);
	MDELAY(10);
	lcm_set_gpio_output(GPIO_LCD_BIAS_ENP, 1);
	MDELAY(10);
#endif

#ifdef BUILD_LK
	ret = TPS65132_write_byte(cmd, data);
#else
	ret = tps65132_write_bytes(cmd, data);
#endif

	if (ret < 0)
		LCM_LOGI("nt35595----tps6132----cmd=%0x--i2c write error----\n", cmd);
	else
		printk("nt35595----tps6132----cmd=%0x--i2c write success----\n", cmd);

	cmd = 0x01;
	data = 0x0E;

#ifdef BUILD_LK
	ret = TPS65132_write_byte(cmd, data);
#else
	ret = tps65132_write_bytes(cmd, data);
#endif

	if (ret < 0)
		LCM_LOGI("nt35595----tps6132----cmd=%0x--i2c write error----\n", cmd);
	else
		printk("nt35595----tps6132----cmd=%0x--i2c write success----\n", cmd);

#endif

	MDELAY(20);

	SET_RESET_PIN(1);
        MDELAY(10);          //>1ms
	SET_RESET_PIN(0);
	MDELAY(20);          //>10us
	
	SET_RESET_PIN(1);
	MDELAY(10);          //>5ms  
	
        push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);

	lcm_set_gpio_output(GPIO_LCD_BL_EN, 1);
}

static void lcm_suspend(void)
{
	lcm_get_gpio_infor();
	lcm_set_gpio_output(GPIO_LCD_BL_EN, 0);
#ifndef CONFIG_FPGA_EARLY_PORTING
#ifndef CONFIG_MTK_LEGACY
	lcm_set_gpio_output(GPIO_LCD_BIAS_ENN, 0);
	lcm_set_gpio_output(GPIO_LCD_BIAS_ENP, 0);
#endif
#endif
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	lcm_set_gpio_output(GPIO_LCD_PWR_EN, 0);
}


static void lcm_resume(void)
{
	lcm_init();
       //push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);

}
         
#if (LCM_DSI_CMD_MODE)
static void lcm_update(unsigned int x, unsigned int y,
                       unsigned int width, unsigned int height)
{
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0>>8)&0xFF);
	unsigned char x0_LSB = (x0&0xFF);
	unsigned char x1_MSB = ((x1>>8)&0xFF);
	unsigned char x1_LSB = (x1&0xFF);
	unsigned char y0_MSB = ((y0>>8)&0xFF);
	unsigned char y0_LSB = (y0&0xFF);
	unsigned char y1_MSB = ((y1>>8)&0xFF);
	unsigned char y1_LSB = (y1&0xFF);

	unsigned int data_array[16];

	data_array[0]= 0x00053902;
	data_array[1]= (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
	data_array[2]= (x1_LSB);
	dsi_set_cmdq(&data_array, 3, 1);

	data_array[0]= 0x00053902;
	data_array[1]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
	data_array[2]= (y1_LSB);
	dsi_set_cmdq(&data_array, 3, 1);
	/*
	data_array[0] = 0x00290508;
	dsi_set_cmdq(&data_array, 1, 1);
	*/
	data_array[0]= 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);
}
#endif

#if 0
static unsigned int lcm_compare_id(void)
{

    int   array[4];
    char  buffer[3];
    char  id0=0;
    char  id1=0;
    char  id2=0;
   
    SET_RESET_PIN(1);
    MDELAY(2);
    SET_RESET_PIN(0);
    UDELAY(11);
    SET_RESET_PIN(1);
    MDELAY(6);

	array[0] = 0x00033700;// read id 
	dsi_set_cmdq(array, 1, 1);
	read_reg_v2(0xDA,buffer, 1);
	
	array[0] = 0x00033700;// read id 
	dsi_set_cmdq(array, 1, 1);
	read_reg_v2(0xDB,buffer+1, 1);
	
	array[0] = 0x00033700;// read id 
	dsi_set_cmdq(array, 1, 1);
	read_reg_v2(0xDC,buffer+2, 1);
	
	id0 = buffer[0]; //should be 0x40
	id1 = buffer[1];//should be 0x00
	id2 = buffer[2];//should be 0x00

	#ifdef BUILD_LK
		printf("zhibin uboot %s\n", __func__);
		printf("%s, id0 = 0x%08x\n", __func__, id0);//should be 0x40
		printf("%s, id1 = 0x%08x\n", __func__, id1);//should be 0x00
		printf("%s, id2 = 0x%08x\n", __func__, id2);//should be 0x00
	#else
		printk("zhibin kernel %s\n", __func__);
                printk("%s, id0 = 0x%08x\n", __func__, id0);//should be 0x40
		printk("%s, id1 = 0x%08x\n", __func__, id1);//should be 0x00
		printk("%s, id2 = 0x%08x\n", __func__, id2);//should be 0x00	
	#endif
		
}
#endif

#if 0
static unsigned int lcm_esd_check(void)
{
#ifndef BUILD_LK
	char  buffer[3];
	int   array[4];

	/// please notice: the max return packet size is 1
	/// if you want to change it, you can refer to the following marked code
	/// but read_reg currently only support read no more than 4 bytes....
	/// if you need to read more, please let BinHan knows.
	/*
			unsigned int data_array[16];
			unsigned int max_return_size = 1;
			
			data_array[0]= 0x00003700 | (max_return_size << 16);	
			
			dsi_set_cmdq(&data_array, 1, 1);
	*/
	array[0] = 0x00023700;// read id return two byte,version and id
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0xA1, buffer, 2);
	if(buffer[0]==0x20 && buffer[1] == 0x75)
	{
		return FALSE;
	}
	else
	{			 
		return TRUE;
	}
#endif

}

static unsigned int lcm_esd_recover(void)
{
	lcm_init();
	lcm_resume();

	return TRUE;
}
#endif

LCM_DRIVER otm1901a_fhd_dsi_vdo_lcm_drv = 
{
        .name		= "otm1901a_fhd_dsi_vdo",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
//	.compare_id    = lcm_compare_id,
//	.esd_check = lcm_esd_check,
//	.esd_recover = lcm_esd_recover,
    #if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
    #endif
    };
