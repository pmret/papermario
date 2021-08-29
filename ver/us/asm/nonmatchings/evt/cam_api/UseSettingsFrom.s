.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UseSettingsFrom
/* F0210 802CB860 27BDFF88 */  addiu     $sp, $sp, -0x78
/* F0214 802CB864 AFB1005C */  sw        $s1, 0x5c($sp)
/* F0218 802CB868 0080882D */  daddu     $s1, $a0, $zero
/* F021C 802CB86C AFBF0064 */  sw        $ra, 0x64($sp)
/* F0220 802CB870 AFB20060 */  sw        $s2, 0x60($sp)
/* F0224 802CB874 AFB00058 */  sw        $s0, 0x58($sp)
/* F0228 802CB878 F7B60070 */  sdc1      $f22, 0x70($sp)
/* F022C 802CB87C F7B40068 */  sdc1      $f20, 0x68($sp)
/* F0230 802CB880 8E30000C */  lw        $s0, 0xc($s1)
/* F0234 802CB884 8E050000 */  lw        $a1, ($s0)
/* F0238 802CB888 0C0B1EAF */  jal       get_variable
/* F023C 802CB88C 26100004 */   addiu    $s0, $s0, 4
/* F0240 802CB890 8E050000 */  lw        $a1, ($s0)
/* F0244 802CB894 26100004 */  addiu     $s0, $s0, 4
/* F0248 802CB898 0220202D */  daddu     $a0, $s1, $zero
/* F024C 802CB89C 3C06800B */  lui       $a2, %hi(gCameras)
/* F0250 802CB8A0 24C61D80 */  addiu     $a2, $a2, %lo(gCameras)
/* F0254 802CB8A4 00021880 */  sll       $v1, $v0, 2
/* F0258 802CB8A8 00621821 */  addu      $v1, $v1, $v0
/* F025C 802CB8AC 00031880 */  sll       $v1, $v1, 2
/* F0260 802CB8B0 00621823 */  subu      $v1, $v1, $v0
/* F0264 802CB8B4 000310C0 */  sll       $v0, $v1, 3
/* F0268 802CB8B8 00621821 */  addu      $v1, $v1, $v0
/* F026C 802CB8BC 000318C0 */  sll       $v1, $v1, 3
/* F0270 802CB8C0 0C0B210B */  jal       evt_get_float_variable
/* F0274 802CB8C4 00669021 */   addu     $s2, $v1, $a2
/* F0278 802CB8C8 8E050000 */  lw        $a1, ($s0)
/* F027C 802CB8CC 26100004 */  addiu     $s0, $s0, 4
/* F0280 802CB8D0 0220202D */  daddu     $a0, $s1, $zero
/* F0284 802CB8D4 0C0B210B */  jal       evt_get_float_variable
/* F0288 802CB8D8 46000586 */   mov.s    $f22, $f0
/* F028C 802CB8DC 0220202D */  daddu     $a0, $s1, $zero
/* F0290 802CB8E0 8E050000 */  lw        $a1, ($s0)
/* F0294 802CB8E4 0C0B210B */  jal       evt_get_float_variable
/* F0298 802CB8E8 46000506 */   mov.s    $f20, $f0
/* F029C 802CB8EC 27A20038 */  addiu     $v0, $sp, 0x38
/* F02A0 802CB8F0 3C0146FF */  lui       $at, 0x46ff
/* F02A4 802CB8F4 3421FE00 */  ori       $at, $at, 0xfe00
/* F02A8 802CB8F8 44812000 */  mtc1      $at, $f4
/* F02AC 802CB8FC 44803000 */  mtc1      $zero, $f6
/* F02B0 802CB900 3C01BF80 */  lui       $at, 0xbf80
/* F02B4 802CB904 44811000 */  mtc1      $at, $f2
/* F02B8 802CB908 3C014120 */  lui       $at, 0x4120
/* F02BC 802CB90C 44817000 */  mtc1      $at, $f14
/* F02C0 802CB910 44060000 */  mfc1      $a2, $f0
/* F02C4 802CB914 4600B306 */  mov.s     $f12, $f22
/* F02C8 802CB918 E7A40044 */  swc1      $f4, 0x44($sp)
/* F02CC 802CB91C AFA20018 */  sw        $v0, 0x18($sp)
/* F02D0 802CB920 27A2003C */  addiu     $v0, $sp, 0x3c
/* F02D4 802CB924 AFA2001C */  sw        $v0, 0x1c($sp)
/* F02D8 802CB928 27A20040 */  addiu     $v0, $sp, 0x40
/* F02DC 802CB92C AFA20020 */  sw        $v0, 0x20($sp)
/* F02E0 802CB930 27A20044 */  addiu     $v0, $sp, 0x44
/* F02E4 802CB934 AFA20024 */  sw        $v0, 0x24($sp)
/* F02E8 802CB938 27A20048 */  addiu     $v0, $sp, 0x48
/* F02EC 802CB93C AFA20028 */  sw        $v0, 0x28($sp)
/* F02F0 802CB940 27A2004C */  addiu     $v0, $sp, 0x4c
/* F02F4 802CB944 AFA2002C */  sw        $v0, 0x2c($sp)
/* F02F8 802CB948 27A20050 */  addiu     $v0, $sp, 0x50
/* F02FC 802CB94C 44073000 */  mfc1      $a3, $f6
/* F0300 802CB950 460EA380 */  add.s     $f14, $f20, $f14
/* F0304 802CB954 E7A20010 */  swc1      $f2, 0x10($sp)
/* F0308 802CB958 E7A60014 */  swc1      $f6, 0x14($sp)
/* F030C 802CB95C 0C017449 */  jal       test_ray_zones
/* F0310 802CB960 AFA20030 */   sw       $v0, 0x30($sp)
/* F0314 802CB964 0040182D */  daddu     $v1, $v0, $zero
/* F0318 802CB968 0460001A */  bltz      $v1, .L802CB9D4
/* F031C 802CB96C 000310C0 */   sll      $v0, $v1, 3
/* F0320 802CB970 00431023 */  subu      $v0, $v0, $v1
/* F0324 802CB974 3C03800E */  lui       $v1, %hi(D_800D91D4)
/* F0328 802CB978 8C6391D4 */  lw        $v1, %lo(D_800D91D4)($v1)
/* F032C 802CB97C 00021080 */  sll       $v0, $v0, 2
/* F0330 802CB980 00431021 */  addu      $v0, $v0, $v1
/* F0334 802CB984 8C420010 */  lw        $v0, 0x10($v0)
/* F0338 802CB988 264304D8 */  addiu     $v1, $s2, 0x4d8
/* F033C 802CB98C 24440020 */  addiu     $a0, $v0, 0x20
.L802CB990:
/* F0340 802CB990 8C480000 */  lw        $t0, ($v0)
/* F0344 802CB994 8C490004 */  lw        $t1, 4($v0)
/* F0348 802CB998 8C4A0008 */  lw        $t2, 8($v0)
/* F034C 802CB99C 8C4B000C */  lw        $t3, 0xc($v0)
/* F0350 802CB9A0 AC680000 */  sw        $t0, ($v1)
/* F0354 802CB9A4 AC690004 */  sw        $t1, 4($v1)
/* F0358 802CB9A8 AC6A0008 */  sw        $t2, 8($v1)
/* F035C 802CB9AC AC6B000C */  sw        $t3, 0xc($v1)
/* F0360 802CB9B0 24420010 */  addiu     $v0, $v0, 0x10
/* F0364 802CB9B4 1444FFF6 */  bne       $v0, $a0, .L802CB990
/* F0368 802CB9B8 24630010 */   addiu    $v1, $v1, 0x10
/* F036C 802CB9BC 8C480000 */  lw        $t0, ($v0)
/* F0370 802CB9C0 8C490004 */  lw        $t1, 4($v0)
/* F0374 802CB9C4 8C4A0008 */  lw        $t2, 8($v0)
/* F0378 802CB9C8 AC680000 */  sw        $t0, ($v1)
/* F037C 802CB9CC AC690004 */  sw        $t1, 4($v1)
/* F0380 802CB9D0 AC6A0008 */  sw        $t2, 8($v1)
.L802CB9D4:
/* F0384 802CB9D4 8FBF0064 */  lw        $ra, 0x64($sp)
/* F0388 802CB9D8 8FB20060 */  lw        $s2, 0x60($sp)
/* F038C 802CB9DC 8FB1005C */  lw        $s1, 0x5c($sp)
/* F0390 802CB9E0 8FB00058 */  lw        $s0, 0x58($sp)
/* F0394 802CB9E4 D7B60070 */  ldc1      $f22, 0x70($sp)
/* F0398 802CB9E8 D7B40068 */  ldc1      $f20, 0x68($sp)
/* F039C 802CB9EC 24020002 */  addiu     $v0, $zero, 2
/* F03A0 802CB9F0 03E00008 */  jr        $ra
/* F03A4 802CB9F4 27BD0078 */   addiu    $sp, $sp, 0x78
