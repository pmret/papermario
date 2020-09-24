.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E6E90
/* 108710 802E6E90 3C028007 */  lui       $v0, 0x8007
/* 108714 802E6E94 8C42419C */  lw        $v0, 0x419c($v0)
/* 108718 802E6E98 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10871C 802E6E9C AFBF0010 */  sw        $ra, 0x10($sp)
/* 108720 802E6EA0 84430086 */  lh        $v1, 0x86($v0)
/* 108724 802E6EA4 2402000B */  addiu     $v0, $zero, 0xb
/* 108728 802E6EA8 14620004 */  bne       $v1, $v0, .L802E6EBC
/* 10872C 802E6EAC 2405000A */   addiu    $a1, $zero, 0xa
/* 108730 802E6EB0 3C04802F */  lui       $a0, 0x802f
/* 108734 802E6EB4 080B9BB1 */  j         .L802E6EC4
/* 108738 802E6EB8 2484AC0C */   addiu    $a0, $a0, -0x53f4
.L802E6EBC:
/* 10873C 802E6EBC 3C04802F */  lui       $a0, 0x802f
/* 108740 802E6EC0 2484ACC8 */  addiu     $a0, $a0, -0x5338
.L802E6EC4:
/* 108744 802E6EC4 0C0B0CF8 */  jal       start_script
/* 108748 802E6EC8 24060020 */   addiu    $a2, $zero, 0x20
/* 10874C 802E6ECC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 108750 802E6ED0 03E00008 */  jr        $ra
/* 108754 802E6ED4 27BD0018 */   addiu    $sp, $sp, 0x18
