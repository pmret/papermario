.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218240_649050
/* 649050 80218240 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 649054 80218244 AFB10014 */  sw        $s1, 0x14($sp)
/* 649058 80218248 0080882D */  daddu     $s1, $a0, $zero
/* 64905C 8021824C AFBF001C */  sw        $ra, 0x1c($sp)
/* 649060 80218250 AFB20018 */  sw        $s2, 0x18($sp)
/* 649064 80218254 AFB00010 */  sw        $s0, 0x10($sp)
/* 649068 80218258 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 64906C 8021825C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 649070 80218260 8E30000C */  lw        $s0, 0xc($s1)
/* 649074 80218264 8E050000 */  lw        $a1, ($s0)
/* 649078 80218268 0C0B1EAF */  jal       evt_get_variable
/* 64907C 8021826C 26100004 */   addiu    $s0, $s0, 4
/* 649080 80218270 8E050000 */  lw        $a1, ($s0)
/* 649084 80218274 26100004 */  addiu     $s0, $s0, 4
/* 649088 80218278 0220202D */  daddu     $a0, $s1, $zero
/* 64908C 8021827C 0C0B1EAF */  jal       evt_get_variable
/* 649090 80218280 0040902D */   daddu    $s2, $v0, $zero
/* 649094 80218284 8E050000 */  lw        $a1, ($s0)
/* 649098 80218288 26100004 */  addiu     $s0, $s0, 4
/* 64909C 8021828C 4482B000 */  mtc1      $v0, $f22
/* 6490A0 80218290 00000000 */  nop
/* 6490A4 80218294 4680B5A0 */  cvt.s.w   $f22, $f22
/* 6490A8 80218298 0C0B1EAF */  jal       evt_get_variable
/* 6490AC 8021829C 0220202D */   daddu    $a0, $s1, $zero
/* 6490B0 802182A0 8E050000 */  lw        $a1, ($s0)
/* 6490B4 802182A4 4482A000 */  mtc1      $v0, $f20
/* 6490B8 802182A8 00000000 */  nop
/* 6490BC 802182AC 4680A520 */  cvt.s.w   $f20, $f20
/* 6490C0 802182B0 0C0B1EAF */  jal       evt_get_variable
/* 6490C4 802182B4 0220202D */   daddu    $a0, $s1, $zero
/* 6490C8 802182B8 8E43000C */  lw        $v1, 0xc($s2)
/* 6490CC 802182BC E4760038 */  swc1      $f22, 0x38($v1)
/* 6490D0 802182C0 8E43000C */  lw        $v1, 0xc($s2)
/* 6490D4 802182C4 E474003C */  swc1      $f20, 0x3c($v1)
/* 6490D8 802182C8 8E43000C */  lw        $v1, 0xc($s2)
/* 6490DC 802182CC 44820000 */  mtc1      $v0, $f0
/* 6490E0 802182D0 00000000 */  nop
/* 6490E4 802182D4 46800020 */  cvt.s.w   $f0, $f0
/* 6490E8 802182D8 E4600040 */  swc1      $f0, 0x40($v1)
/* 6490EC 802182DC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6490F0 802182E0 8FB20018 */  lw        $s2, 0x18($sp)
/* 6490F4 802182E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 6490F8 802182E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 6490FC 802182EC D7B60028 */  ldc1      $f22, 0x28($sp)
/* 649100 802182F0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 649104 802182F4 24020002 */  addiu     $v0, $zero, 2
/* 649108 802182F8 03E00008 */  jr        $ra
/* 64910C 802182FC 27BD0030 */   addiu    $sp, $sp, 0x30
