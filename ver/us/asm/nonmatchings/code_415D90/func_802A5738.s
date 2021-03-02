.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A5738
/* 41A4C8 802A5738 3C02802B */  lui       $v0, %hi(D_802AD604)
/* 41A4CC 802A573C 9042D604 */  lbu       $v0, %lo(D_802AD604)($v0)
/* 41A4D0 802A5740 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 41A4D4 802A5744 24420001 */  addiu     $v0, $v0, 1
/* 41A4D8 802A5748 00021600 */  sll       $v0, $v0, 0x18
/* 41A4DC 802A574C 00021E03 */  sra       $v1, $v0, 0x18
/* 41A4E0 802A5750 2C620020 */  sltiu     $v0, $v1, 0x20
/* 41A4E4 802A5754 10400019 */  beqz      $v0, L802A57BC_41A54C
/* 41A4E8 802A5758 AFBF0018 */   sw       $ra, 0x18($sp)
/* 41A4EC 802A575C 00031080 */  sll       $v0, $v1, 2
/* 41A4F0 802A5760 3C01802B */  lui       $at, %hi(jtbl_802ABB58)
/* 41A4F4 802A5764 00220821 */  addu      $at, $at, $v0
/* 41A4F8 802A5768 8C22BB58 */  lw        $v0, %lo(jtbl_802ABB58)($at)
/* 41A4FC 802A576C 00400008 */  jr        $v0
/* 41A500 802A5770 00000000 */   nop
glabel L802A5774_41A504
/* 41A504 802A5774 3C02802B */  lui       $v0, %hi(D_802AD60B)
/* 41A508 802A5778 8042D60B */  lb        $v0, %lo(D_802AD60B)($v0)
/* 41A50C 802A577C 1040000F */  beqz      $v0, L802A57BC_41A54C
/* 41A510 802A5780 00000000 */   nop
/* 41A514 802A5784 3C02802B */  lui       $v0, %hi(D_802AD605)
/* 41A518 802A5788 8042D605 */  lb        $v0, %lo(D_802AD605)($v0)
/* 41A51C 802A578C 3C03802B */  lui       $v1, %hi(D_802AD614)
/* 41A520 802A5790 8063D614 */  lb        $v1, %lo(D_802AD614)($v1)
/* 41A524 802A5794 3C07802B */  lui       $a3, %hi(D_802AD624)
/* 41A528 802A5798 8CE7D624 */  lw        $a3, %lo(D_802AD624)($a3)
/* 41A52C 802A579C AFA00014 */  sw        $zero, 0x14($sp)
/* 41A530 802A57A0 00021080 */  sll       $v0, $v0, 2
/* 41A534 802A57A4 AFA30010 */  sw        $v1, 0x10($sp)
/* 41A538 802A57A8 3C04802B */  lui       $a0, %hi(D_802AD6C0)
/* 41A53C 802A57AC 00822021 */  addu      $a0, $a0, $v0
/* 41A540 802A57B0 8C84D6C0 */  lw        $a0, %lo(D_802AD6C0)($a0)
/* 41A544 802A57B4 0C04993B */  jal       draw_msg
/* 41A548 802A57B8 24A50008 */   addiu    $a1, $a1, 8
glabel L802A57BC_41A54C
/* 41A54C 802A57BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 41A550 802A57C0 03E00008 */  jr        $ra
/* 41A554 802A57C4 27BD0020 */   addiu    $sp, $sp, 0x20
