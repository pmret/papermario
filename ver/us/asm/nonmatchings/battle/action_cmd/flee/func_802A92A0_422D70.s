.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A92A0_422D70
/* 422D70 802A92A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 422D74 802A92A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 422D78 802A92A8 0080902D */  daddu     $s2, $a0, $zero
/* 422D7C 802A92AC AFBF001C */  sw        $ra, 0x1c($sp)
/* 422D80 802A92B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 422D84 802A92B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 422D88 802A92B8 0C09A216 */  jal       func_80268858
/* 422D8C 802A92BC 8E50000C */   lw       $s0, 0xc($s2)
/* 422D90 802A92C0 0240202D */  daddu     $a0, $s2, $zero
/* 422D94 802A92C4 8E050000 */  lw        $a1, ($s0)
/* 422D98 802A92C8 0C0B1EAF */  jal       get_variable
/* 422D9C 802A92CC 26100004 */   addiu    $s0, $s0, 4
/* 422DA0 802A92D0 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 422DA4 802A92D4 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 422DA8 802A92D8 A622004E */  sh        $v0, 0x4e($s1)
/* 422DAC 802A92DC 8E050000 */  lw        $a1, ($s0)
/* 422DB0 802A92E0 26100004 */  addiu     $s0, $s0, 4
/* 422DB4 802A92E4 0C0B1EAF */  jal       get_variable
/* 422DB8 802A92E8 0240202D */   daddu    $a0, $s2, $zero
/* 422DBC 802A92EC A6220052 */  sh        $v0, 0x52($s1)
/* 422DC0 802A92F0 8E050000 */  lw        $a1, ($s0)
/* 422DC4 802A92F4 0C0B1EAF */  jal       get_variable
/* 422DC8 802A92F8 0240202D */   daddu    $a0, $s2, $zero
/* 422DCC 802A92FC 00022400 */  sll       $a0, $v0, 0x10
/* 422DD0 802A9300 00042403 */  sra       $a0, $a0, 0x10
/* 422DD4 802A9304 0C09A089 */  jal       func_80268224
/* 422DD8 802A9308 A6220050 */   sh       $v0, 0x50($s1)
/* 422DDC 802A930C 3C07FFFF */  lui       $a3, 0xffff
/* 422DE0 802A9310 34E77FFF */  ori       $a3, $a3, 0x7fff
/* 422DE4 802A9314 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 422DE8 802A9318 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
/* 422DEC 802A931C A6220050 */  sh        $v0, 0x50($s1)
/* 422DF0 802A9320 A2200060 */  sb        $zero, 0x60($s1)
/* 422DF4 802A9324 A0A00081 */  sb        $zero, 0x81($a1)
/* 422DF8 802A9328 82230080 */  lb        $v1, 0x80($s1)
/* 422DFC 802A932C 2404007F */  addiu     $a0, $zero, 0x7f
/* 422E00 802A9330 A0A40086 */  sb        $a0, 0x86($a1)
/* 422E04 802A9334 8CA40000 */  lw        $a0, ($a1)
/* 422E08 802A9338 2463FFFF */  addiu     $v1, $v1, -1
/* 422E0C 802A933C 00031840 */  sll       $v1, $v1, 1
/* 422E10 802A9340 00711821 */  addu      $v1, $v1, $s1
/* 422E14 802A9344 00872024 */  and       $a0, $a0, $a3
/* 422E18 802A9348 90660075 */  lbu       $a2, 0x75($v1)
/* 422E1C 802A934C 2403000A */  addiu     $v1, $zero, 0xa
/* 422E20 802A9350 ACA40000 */  sw        $a0, ($a1)
/* 422E24 802A9354 A623004C */  sh        $v1, 0x4c($s1)
/* 422E28 802A9358 A0A60082 */  sb        $a2, 0x82($a1)
/* 422E2C 802A935C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 422E30 802A9360 8FB20018 */  lw        $s2, 0x18($sp)
/* 422E34 802A9364 8FB10014 */  lw        $s1, 0x14($sp)
/* 422E38 802A9368 8FB00010 */  lw        $s0, 0x10($sp)
/* 422E3C 802A936C 24020002 */  addiu     $v0, $zero, 2
/* 422E40 802A9370 03E00008 */  jr        $ra
/* 422E44 802A9374 27BD0020 */   addiu    $sp, $sp, 0x20
