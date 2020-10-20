.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241474
/* 9FBC64 80241474 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9FBC68 80241478 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FBC6C 8024147C 0080882D */  daddu     $s1, $a0, $zero
/* 9FBC70 80241480 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9FBC74 80241484 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FBC78 80241488 8E300148 */  lw        $s0, 0x148($s1)
/* 9FBC7C 8024148C 0C00EABB */  jal       get_npc_unsafe
/* 9FBC80 80241490 86040008 */   lh       $a0, 8($s0)
/* 9FBC84 80241494 8E0300CC */  lw        $v1, 0xcc($s0)
/* 9FBC88 80241498 3C014120 */  lui       $at, 0x4120
/* 9FBC8C 8024149C 44812000 */  mtc1      $at, $f4
/* 9FBC90 802414A0 3C014000 */  lui       $at, 0x4000
/* 9FBC94 802414A4 44810000 */  mtc1      $at, $f0
/* 9FBC98 802414A8 C442003C */  lwc1      $f2, 0x3c($v0)
/* 9FBC9C 802414AC 8C640010 */  lw        $a0, 0x10($v1)
/* 9FBCA0 802414B0 8C430000 */  lw        $v1, ($v0)
/* 9FBCA4 802414B4 E444001C */  swc1      $f4, 0x1c($v0)
/* 9FBCA8 802414B8 E4400014 */  swc1      $f0, 0x14($v0)
/* 9FBCAC 802414BC E4420064 */  swc1      $f2, 0x64($v0)
/* 9FBCB0 802414C0 34630800 */  ori       $v1, $v1, 0x800
/* 9FBCB4 802414C4 AC430000 */  sw        $v1, ($v0)
/* 9FBCB8 802414C8 AC440028 */  sw        $a0, 0x28($v0)
/* 9FBCBC 802414CC 2402000B */  addiu     $v0, $zero, 0xb
/* 9FBCC0 802414D0 AE220070 */  sw        $v0, 0x70($s1)
/* 9FBCC4 802414D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9FBCC8 802414D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FBCCC 802414DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FBCD0 802414E0 03E00008 */  jr        $ra
/* 9FBCD4 802414E4 27BD0020 */   addiu    $sp, $sp, 0x20
