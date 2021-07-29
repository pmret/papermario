.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_init_component_anim_state
/* 1008A0 802DD7B0 2403FFFF */  addiu     $v1, $zero, -1
/* 1008A4 802DD7B4 14A30003 */  bne       $a1, $v1, .L802DD7C4
/* 1008A8 802DD7B8 24020001 */   addiu    $v0, $zero, 1
/* 1008AC 802DD7BC 03E00008 */  jr        $ra
/* 1008B0 802DD7C0 AC800000 */   sw       $zero, ($a0)
.L802DD7C4:
/* 1008B4 802DD7C4 AC820000 */  sw        $v0, ($a0)
/* 1008B8 802DD7C8 AC800004 */  sw        $zero, 4($a0)
/* 1008BC 802DD7CC 8CA20000 */  lw        $v0, ($a1)
/* 1008C0 802DD7D0 3C013F80 */  lui       $at, 0x3f80
/* 1008C4 802DD7D4 44810000 */  mtc1      $at, $f0
/* 1008C8 802DD7D8 AC80000C */  sw        $zero, 0xc($a0)
/* 1008CC 802DD7DC AC800010 */  sw        $zero, 0x10($a0)
/* 1008D0 802DD7E0 AC830014 */  sw        $v1, 0x14($a0)
/* 1008D4 802DD7E4 AC830018 */  sw        $v1, 0x18($a0)
/* 1008D8 802DD7E8 AC80001C */  sw        $zero, 0x1c($a0)
/* 1008DC 802DD7EC AC800020 */  sw        $zero, 0x20($a0)
/* 1008E0 802DD7F0 AC800024 */  sw        $zero, 0x24($a0)
/* 1008E4 802DD7F4 AC800028 */  sw        $zero, 0x28($a0)
/* 1008E8 802DD7F8 AC80002C */  sw        $zero, 0x2c($a0)
/* 1008EC 802DD7FC AC800030 */  sw        $zero, 0x30($a0)
/* 1008F0 802DD800 AC800034 */  sw        $zero, 0x34($a0)
/* 1008F4 802DD804 AC800038 */  sw        $zero, 0x38($a0)
/* 1008F8 802DD808 AC80003C */  sw        $zero, 0x3c($a0)
/* 1008FC 802DD80C AC820008 */  sw        $v0, 8($a0)
/* 100900 802DD810 E4800040 */  swc1      $f0, 0x40($a0)
/* 100904 802DD814 E4800044 */  swc1      $f0, 0x44($a0)
/* 100908 802DD818 03E00008 */  jr        $ra
/* 10090C 802DD81C E4800048 */   swc1     $f0, 0x48($a0)
