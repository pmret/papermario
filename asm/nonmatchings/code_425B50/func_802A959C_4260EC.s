.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A959C_4260EC
/* 4260EC 802A959C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4260F0 802A95A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4260F4 802A95A4 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 4260F8 802A95A8 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 4260FC 802A95AC AFBF0014 */  sw        $ra, 0x14($sp)
/* 426100 802A95B0 0C05123D */  jal       free_icon
/* 426104 802A95B4 8E040004 */   lw       $a0, 4($s0)
/* 426108 802A95B8 0C05123D */  jal       free_icon
/* 42610C 802A95BC 8E040008 */   lw       $a0, 8($s0)
/* 426110 802A95C0 0C05123D */  jal       free_icon
/* 426114 802A95C4 8E04000C */   lw       $a0, 0xc($s0)
/* 426118 802A95C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42611C 802A95CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 426120 802A95D0 03E00008 */  jr        $ra
/* 426124 802A95D4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 426128 802A95D8 00000000 */  nop
/* 42612C 802A95DC 00000000 */  nop
