.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244288_9DB2A8
/* 9DB2A8 80244288 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9DB2AC 8024428C AFB00010 */  sw        $s0, 0x10($sp)
/* 9DB2B0 80244290 0080802D */  daddu     $s0, $a0, $zero
/* 9DB2B4 80244294 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9DB2B8 80244298 8E02000C */  lw        $v0, 0xc($s0)
/* 9DB2BC 8024429C 0C0B1EAF */  jal       get_variable
/* 9DB2C0 802442A0 8C450000 */   lw       $a1, ($v0)
/* 9DB2C4 802442A4 0200202D */  daddu     $a0, $s0, $zero
/* 9DB2C8 802442A8 2442FFFF */  addiu     $v0, $v0, -1
/* 9DB2CC 802442AC 000218C0 */  sll       $v1, $v0, 3
/* 9DB2D0 802442B0 00621823 */  subu      $v1, $v1, $v0
/* 9DB2D4 802442B4 00031880 */  sll       $v1, $v1, 2
/* 9DB2D8 802442B8 3C058025 */  lui       $a1, %hi(D_80252798_9E97B8)
/* 9DB2DC 802442BC 00A32821 */  addu      $a1, $a1, $v1
/* 9DB2E0 802442C0 8CA52798 */  lw        $a1, %lo(D_80252798_9E97B8)($a1)
/* 9DB2E4 802442C4 0C0B2026 */  jal       evt_set_variable
/* 9DB2E8 802442C8 24060001 */   addiu    $a2, $zero, 1
/* 9DB2EC 802442CC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9DB2F0 802442D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DB2F4 802442D4 24020002 */  addiu     $v0, $zero, 2
/* 9DB2F8 802442D8 03E00008 */  jr        $ra
/* 9DB2FC 802442DC 27BD0018 */   addiu    $sp, $sp, 0x18
