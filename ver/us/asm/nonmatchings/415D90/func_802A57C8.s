.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A57C8
/* 41A558 802A57C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 41A55C 802A57CC 24A5000B */  addiu     $a1, $a1, 0xb
/* 41A560 802A57D0 3C03802B */  lui       $v1, %hi(D_802AD610)
/* 41A564 802A57D4 8463D610 */  lh        $v1, %lo(D_802AD610)($v1)
/* 41A568 802A57D8 24C60006 */  addiu     $a2, $a2, 6
/* 41A56C 802A57DC 14600004 */  bnez      $v1, .L802A57F0
/* 41A570 802A57E0 AFBF0018 */   sw       $ra, 0x18($sp)
/* 41A574 802A57E4 3C04001D */  lui       $a0, 0x1d
/* 41A578 802A57E8 080A95FE */  j         .L802A57F8
/* 41A57C 802A57EC 348400CB */   ori      $a0, $a0, 0xcb
.L802A57F0:
/* 41A580 802A57F0 3C04001D */  lui       $a0, 0x1d
/* 41A584 802A57F4 348400CC */  ori       $a0, $a0, 0xcc
.L802A57F8:
/* 41A588 802A57F8 2402000F */  addiu     $v0, $zero, 0xf
/* 41A58C 802A57FC 240700FF */  addiu     $a3, $zero, 0xff
/* 41A590 802A5800 AFA20010 */  sw        $v0, 0x10($sp)
/* 41A594 802A5804 0C04993B */  jal       draw_msg
/* 41A598 802A5808 AFA00014 */   sw       $zero, 0x14($sp)
/* 41A59C 802A580C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 41A5A0 802A5810 03E00008 */  jr        $ra
/* 41A5A4 802A5814 27BD0020 */   addiu    $sp, $sp, 0x20
