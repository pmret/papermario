.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240044_8008C4
/* 8008C4 80240044 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8008C8 80240048 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8008CC 8024004C AFB10014 */  sw        $s1, 0x14($sp)
/* 8008D0 80240050 AFB00010 */  sw        $s0, 0x10($sp)
/* 8008D4 80240054 8C82000C */  lw        $v0, 0xc($a0)
/* 8008D8 80240058 0C0B1EAF */  jal       get_variable
/* 8008DC 8024005C 8C450000 */   lw       $a1, ($v0)
/* 8008E0 80240060 0000202D */  daddu     $a0, $zero, $zero
/* 8008E4 80240064 3C05FD05 */  lui       $a1, 0xfd05
/* 8008E8 80240068 34A50F82 */  ori       $a1, $a1, 0xf82
/* 8008EC 8024006C 0C0B1EAF */  jal       get_variable
/* 8008F0 80240070 0040802D */   daddu    $s0, $v0, $zero
/* 8008F4 80240074 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 8008F8 80240078 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 8008FC 8024007C 24050040 */  addiu     $a1, $zero, 0x40
/* 800900 80240080 8C640140 */  lw        $a0, 0x140($v1)
/* 800904 80240084 00101900 */  sll       $v1, $s0, 4
/* 800908 80240088 00641821 */  addu      $v1, $v1, $a0
/* 80090C 8024008C 8C640000 */  lw        $a0, ($v1)
/* 800910 80240090 0C04D052 */  jal       set_item_entity_flags
/* 800914 80240094 0040882D */   daddu    $s1, $v0, $zero
/* 800918 80240098 0000202D */  daddu     $a0, $zero, $zero
/* 80091C 8024009C 00108080 */  sll       $s0, $s0, 2
/* 800920 802400A0 02118021 */  addu      $s0, $s0, $s1
/* 800924 802400A4 8E050000 */  lw        $a1, ($s0)
/* 800928 802400A8 0C0B2026 */  jal       set_variable
/* 80092C 802400AC 24060001 */   addiu    $a2, $zero, 1
/* 800930 802400B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 800934 802400B4 8FB10014 */  lw        $s1, 0x14($sp)
/* 800938 802400B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 80093C 802400BC 24020002 */  addiu     $v0, $zero, 2
/* 800940 802400C0 03E00008 */  jr        $ra
/* 800944 802400C4 27BD0020 */   addiu    $sp, $sp, 0x20
