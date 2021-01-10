.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A911C_429E3C
/* 429E3C 802A911C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 429E40 802A9120 AFB20018 */  sw        $s2, 0x18($sp)
/* 429E44 802A9124 0080902D */  daddu     $s2, $a0, $zero
/* 429E48 802A9128 AFB10014 */  sw        $s1, 0x14($sp)
/* 429E4C 802A912C 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 429E50 802A9130 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 429E54 802A9134 AFB3001C */  sw        $s3, 0x1c($sp)
/* 429E58 802A9138 3C13800E */  lui       $s3, %hi(gBattleStatus)
/* 429E5C 802A913C 2673C070 */  addiu     $s3, $s3, %lo(gBattleStatus)
/* 429E60 802A9140 AFBF0020 */  sw        $ra, 0x20($sp)
/* 429E64 802A9144 AFB00010 */  sw        $s0, 0x10($sp)
/* 429E68 802A9148 82620083 */  lb        $v0, 0x83($s3)
/* 429E6C 802A914C 8E50000C */  lw        $s0, 0xc($s2)
/* 429E70 802A9150 10400024 */  beqz      $v0, .L802A91E4
/* 429E74 802A9154 0260182D */   daddu    $v1, $s3, $zero
/* 429E78 802A9158 0C09A216 */  jal       func_80268858
/* 429E7C 802A915C 00000000 */   nop      
/* 429E80 802A9160 8E050000 */  lw        $a1, ($s0)
/* 429E84 802A9164 26100004 */  addiu     $s0, $s0, 4
/* 429E88 802A9168 0C0B1EAF */  jal       get_variable
/* 429E8C 802A916C 0240202D */   daddu    $a0, $s2, $zero
/* 429E90 802A9170 A622004E */  sh        $v0, 0x4e($s1)
/* 429E94 802A9174 8E050000 */  lw        $a1, ($s0)
/* 429E98 802A9178 26100004 */  addiu     $s0, $s0, 4
/* 429E9C 802A917C 0C0B1EAF */  jal       get_variable
/* 429EA0 802A9180 0240202D */   daddu    $a0, $s2, $zero
/* 429EA4 802A9184 A6220052 */  sh        $v0, 0x52($s1)
/* 429EA8 802A9188 8E050000 */  lw        $a1, ($s0)
/* 429EAC 802A918C 0C0B1EAF */  jal       get_variable
/* 429EB0 802A9190 0240202D */   daddu    $a0, $s2, $zero
/* 429EB4 802A9194 00022400 */  sll       $a0, $v0, 0x10
/* 429EB8 802A9198 00042403 */  sra       $a0, $a0, 0x10
/* 429EBC 802A919C 0C09A089 */  jal       func_80268224
/* 429EC0 802A91A0 A6220050 */   sh       $v0, 0x50($s1)
/* 429EC4 802A91A4 3C04FFFF */  lui       $a0, 0xffff
/* 429EC8 802A91A8 34847FFF */  ori       $a0, $a0, 0x7fff
/* 429ECC 802A91AC A6220050 */  sh        $v0, 0x50($s1)
/* 429ED0 802A91B0 A2200060 */  sb        $zero, 0x60($s1)
/* 429ED4 802A91B4 A6200044 */  sh        $zero, 0x44($s1)
/* 429ED8 802A91B8 A6200048 */  sh        $zero, 0x48($s1)
/* 429EDC 802A91BC 8E620000 */  lw        $v0, ($s3)
/* 429EE0 802A91C0 2403000A */  addiu     $v1, $zero, 0xa
/* 429EE4 802A91C4 A2600081 */  sb        $zero, 0x81($s3)
/* 429EE8 802A91C8 A2600086 */  sb        $zero, 0x86($s3)
/* 429EEC 802A91CC A623004C */  sh        $v1, 0x4c($s1)
/* 429EF0 802A91D0 00441024 */  and       $v0, $v0, $a0
/* 429EF4 802A91D4 0C09A446 */  jal       func_80269118
/* 429EF8 802A91D8 AE620000 */   sw       $v0, ($s3)
/* 429EFC 802A91DC 080AA47B */  j         .L802A91EC
/* 429F00 802A91E0 24020002 */   addiu    $v0, $zero, 2
.L802A91E4:
/* 429F04 802A91E4 A0600081 */  sb        $zero, 0x81($v1)
/* 429F08 802A91E8 24020002 */  addiu     $v0, $zero, 2
.L802A91EC:
/* 429F0C 802A91EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 429F10 802A91F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 429F14 802A91F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 429F18 802A91F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 429F1C 802A91FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 429F20 802A9200 03E00008 */  jr        $ra
/* 429F24 802A9204 27BD0028 */   addiu    $sp, $sp, 0x28
