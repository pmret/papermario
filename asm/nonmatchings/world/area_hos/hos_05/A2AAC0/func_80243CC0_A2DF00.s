.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243CC0_A2DF00
/* A2DF00 80243CC0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A2DF04 80243CC4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A2DF08 80243CC8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A2DF0C 80243CCC 3C04800B */  lui       $a0, %hi(gCameras)
/* A2DF10 80243CD0 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A2DF14 80243CD4 AFBF0028 */  sw        $ra, 0x28($sp)
/* A2DF18 80243CD8 AFB30024 */  sw        $s3, 0x24($sp)
/* A2DF1C 80243CDC AFB20020 */  sw        $s2, 0x20($sp)
/* A2DF20 80243CE0 AFB1001C */  sw        $s1, 0x1c($sp)
/* A2DF24 80243CE4 AFB00018 */  sw        $s0, 0x18($sp)
/* A2DF28 80243CE8 00031080 */  sll       $v0, $v1, 2
/* A2DF2C 80243CEC 00431021 */  addu      $v0, $v0, $v1
/* A2DF30 80243CF0 00021080 */  sll       $v0, $v0, 2
/* A2DF34 80243CF4 00431023 */  subu      $v0, $v0, $v1
/* A2DF38 80243CF8 000218C0 */  sll       $v1, $v0, 3
/* A2DF3C 80243CFC 00431021 */  addu      $v0, $v0, $v1
/* A2DF40 80243D00 000210C0 */  sll       $v0, $v0, 3
/* A2DF44 80243D04 00441021 */  addu      $v0, $v0, $a0
/* A2DF48 80243D08 8451000E */  lh        $s1, 0xe($v0)
/* A2DF4C 80243D0C 0C090DC3 */  jal       func_8024370C_A2D94C
/* A2DF50 80243D10 84520010 */   lh       $s2, 0x10($v0)
/* A2DF54 80243D14 3C05FF10 */  lui       $a1, 0xff10
/* A2DF58 80243D18 3C10800A */  lui       $s0, %hi(D_8009A66C)
/* A2DF5C 80243D1C 2610A66C */  addiu     $s0, $s0, %lo(D_8009A66C)
/* A2DF60 80243D20 34A5013F */  ori       $a1, $a1, 0x13f
/* A2DF64 80243D24 8E060000 */  lw        $a2, ($s0)
/* A2DF68 80243D28 3C02DE00 */  lui       $v0, 0xde00
/* A2DF6C 80243D2C 00C0202D */  daddu     $a0, $a2, $zero
/* A2DF70 80243D30 24C60008 */  addiu     $a2, $a2, 8
/* A2DF74 80243D34 AE060000 */  sw        $a2, ($s0)
/* A2DF78 80243D38 3C03800A */  lui       $v1, %hi(D_8009A64C)
/* A2DF7C 80243D3C 8C63A64C */  lw        $v1, %lo(D_8009A64C)($v1)
/* A2DF80 80243D40 3C138025 */  lui       $s3, %hi(D_8024AA20)
/* A2DF84 80243D44 2673AA20 */  addiu     $s3, $s3, %lo(D_8024AA20)
/* A2DF88 80243D48 AC820000 */  sw        $v0, ($a0)
/* A2DF8C 80243D4C 8E670000 */  lw        $a3, ($s3)
/* A2DF90 80243D50 3C028025 */  lui       $v0, %hi(D_8024AA28)
/* A2DF94 80243D54 2442AA28 */  addiu     $v0, $v0, %lo(D_8024AA28)
/* A2DF98 80243D58 AC820004 */  sw        $v0, 4($a0)
/* A2DF9C 80243D5C ACC50000 */  sw        $a1, ($a2)
/* A2DFA0 80243D60 ACC30004 */  sw        $v1, 4($a2)
/* A2DFA4 80243D64 84E2005A */  lh        $v0, 0x5a($a3)
/* A2DFA8 80243D68 24C30008 */  addiu     $v1, $a2, 8
/* A2DFAC 80243D6C 284200FF */  slti      $v0, $v0, 0xff
/* A2DFB0 80243D70 1040000F */  beqz      $v0, .L80243DB0
/* A2DFB4 80243D74 AE030000 */   sw       $v1, ($s0)
/* A2DFB8 80243D78 3C04E200 */  lui       $a0, 0xe200
/* A2DFBC 80243D7C 3484001C */  ori       $a0, $a0, 0x1c
/* A2DFC0 80243D80 3C030050 */  lui       $v1, 0x50
/* A2DFC4 80243D84 34634340 */  ori       $v1, $v1, 0x4340
/* A2DFC8 80243D88 24C20010 */  addiu     $v0, $a2, 0x10
/* A2DFCC 80243D8C AE020000 */  sw        $v0, ($s0)
/* A2DFD0 80243D90 24C20018 */  addiu     $v0, $a2, 0x18
/* A2DFD4 80243D94 ACC40008 */  sw        $a0, 8($a2)
/* A2DFD8 80243D98 ACC3000C */  sw        $v1, 0xc($a2)
/* A2DFDC 80243D9C AE020000 */  sw        $v0, ($s0)
/* A2DFE0 80243DA0 3C02FA00 */  lui       $v0, 0xfa00
/* A2DFE4 80243DA4 ACC20010 */  sw        $v0, 0x10($a2)
/* A2DFE8 80243DA8 90E2005B */  lbu       $v0, 0x5b($a3)
/* A2DFEC 80243DAC ACC20014 */  sw        $v0, 0x14($a2)
.L80243DB0:
/* A2DFF0 80243DB0 24040001 */  addiu     $a0, $zero, 1
/* A2DFF4 80243DB4 27A50010 */  addiu     $a1, $sp, 0x10
/* A2DFF8 80243DB8 0C04DF70 */  jal       func_80137DC0
/* A2DFFC 80243DBC 27A60014 */   addiu    $a2, $sp, 0x14
/* A2E000 80243DC0 C7A20014 */  lwc1      $f2, 0x14($sp)
/* A2E004 80243DC4 44800000 */  mtc1      $zero, $f0
/* A2E008 80243DC8 00000000 */  nop       
/* A2E00C 80243DCC 46001032 */  c.eq.s    $f2, $f0
/* A2E010 80243DD0 00000000 */  nop       
/* A2E014 80243DD4 45010016 */  bc1t      .L80243E30
/* A2E018 80243DD8 3C05FC35 */   lui      $a1, 0xfc35
/* A2E01C 80243DDC 34A57E6A */  ori       $a1, $a1, 0x7e6a
/* A2E020 80243DE0 3C0411FC */  lui       $a0, 0x11fc
/* A2E024 80243DE4 3484FC7E */  ori       $a0, $a0, 0xfc7e
/* A2E028 80243DE8 3C06D0D0 */  lui       $a2, 0xd0d0
/* A2E02C 80243DEC 8E030000 */  lw        $v1, ($s0)
/* A2E030 80243DF0 34C6D000 */  ori       $a2, $a2, 0xd000
/* A2E034 80243DF4 0060102D */  daddu     $v0, $v1, $zero
/* A2E038 80243DF8 24630008 */  addiu     $v1, $v1, 8
/* A2E03C 80243DFC AE030000 */  sw        $v1, ($s0)
/* A2E040 80243E00 AC450000 */  sw        $a1, ($v0)
/* A2E044 80243E04 AC440004 */  sw        $a0, 4($v0)
/* A2E048 80243E08 24620008 */  addiu     $v0, $v1, 8
/* A2E04C 80243E0C AE020000 */  sw        $v0, ($s0)
/* A2E050 80243E10 3C02FA00 */  lui       $v0, 0xfa00
/* A2E054 80243E14 AC620000 */  sw        $v0, ($v1)
/* A2E058 80243E18 4600110D */  trunc.w.s $f4, $f2
/* A2E05C 80243E1C 44022000 */  mfc1      $v0, $f4
/* A2E060 80243E20 00000000 */  nop       
/* A2E064 80243E24 304200FF */  andi      $v0, $v0, 0xff
/* A2E068 80243E28 00461025 */  or        $v0, $v0, $a2
/* A2E06C 80243E2C AC620004 */  sw        $v0, 4($v1)
.L80243E30:
/* A2E070 80243E30 8E630000 */  lw        $v1, ($s3)
/* A2E074 80243E34 84620058 */  lh        $v0, 0x58($v1)
/* A2E078 80243E38 1440000F */  bnez      $v0, .L80243E78
/* A2E07C 80243E3C 00000000 */   nop      
/* A2E080 80243E40 8C66000C */  lw        $a2, 0xc($v1)
/* A2E084 80243E44 8C670010 */  lw        $a3, 0x10($v1)
/* A2E088 80243E48 84640040 */  lh        $a0, 0x40($v1)
/* A2E08C 80243E4C 84650042 */  lh        $a1, 0x42($v1)
/* A2E090 80243E50 02242021 */  addu      $a0, $s1, $a0
/* A2E094 80243E54 0C090DD6 */  jal       func_80243758_A2D998
/* A2E098 80243E58 02452821 */   addu     $a1, $s2, $a1
/* A2E09C 80243E5C 8E620000 */  lw        $v0, ($s3)
/* A2E0A0 80243E60 8C460004 */  lw        $a2, 4($v0)
/* A2E0A4 80243E64 8C470008 */  lw        $a3, 8($v0)
/* A2E0A8 80243E68 8444003C */  lh        $a0, 0x3c($v0)
/* A2E0AC 80243E6C 8445003E */  lh        $a1, 0x3e($v0)
/* A2E0B0 80243E70 08090FAB */  j         .L80243EAC
/* A2E0B4 80243E74 02242021 */   addu     $a0, $s1, $a0
.L80243E78:
/* A2E0B8 80243E78 8C660004 */  lw        $a2, 4($v1)
/* A2E0BC 80243E7C 8C670008 */  lw        $a3, 8($v1)
/* A2E0C0 80243E80 8464003C */  lh        $a0, 0x3c($v1)
/* A2E0C4 80243E84 8465003E */  lh        $a1, 0x3e($v1)
/* A2E0C8 80243E88 02242021 */  addu      $a0, $s1, $a0
/* A2E0CC 80243E8C 0C090DD6 */  jal       func_80243758_A2D998
/* A2E0D0 80243E90 02452821 */   addu     $a1, $s2, $a1
/* A2E0D4 80243E94 8E620000 */  lw        $v0, ($s3)
/* A2E0D8 80243E98 8C46000C */  lw        $a2, 0xc($v0)
/* A2E0DC 80243E9C 8C470010 */  lw        $a3, 0x10($v0)
/* A2E0E0 80243EA0 84440040 */  lh        $a0, 0x40($v0)
/* A2E0E4 80243EA4 84450042 */  lh        $a1, 0x42($v0)
/* A2E0E8 80243EA8 02242021 */  addu      $a0, $s1, $a0
.L80243EAC:
/* A2E0EC 80243EAC 0C090DD6 */  jal       func_80243758_A2D998
/* A2E0F0 80243EB0 02452821 */   addu     $a1, $s2, $a1
/* A2E0F4 80243EB4 8FBF0028 */  lw        $ra, 0x28($sp)
/* A2E0F8 80243EB8 8FB30024 */  lw        $s3, 0x24($sp)
/* A2E0FC 80243EBC 8FB20020 */  lw        $s2, 0x20($sp)
/* A2E100 80243EC0 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2E104 80243EC4 8FB00018 */  lw        $s0, 0x18($sp)
/* A2E108 80243EC8 03E00008 */  jr        $ra
/* A2E10C 80243ECC 27BD0030 */   addiu    $sp, $sp, 0x30
