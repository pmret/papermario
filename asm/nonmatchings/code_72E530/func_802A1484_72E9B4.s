.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1484_72E9B4
/* 72E9B4 802A1484 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 72E9B8 802A1488 AFB00010 */  sw        $s0, 0x10($sp)
/* 72E9BC 802A148C 0080802D */  daddu     $s0, $a0, $zero
/* 72E9C0 802A1490 AFBF0014 */  sw        $ra, 0x14($sp)
/* 72E9C4 802A1494 8E02000C */  lw        $v0, 0xc($s0)
/* 72E9C8 802A1498 0C0B1EAF */  jal       get_variable
/* 72E9CC 802A149C 8C450000 */   lw       $a1, ($v0)
/* 72E9D0 802A14A0 3C038008 */  lui       $v1, %hi(gItemTable)
/* 72E9D4 802A14A4 246378E0 */  addiu     $v1, $v1, %lo(gItemTable)
/* 72E9D8 802A14A8 00021140 */  sll       $v0, $v0, 5
/* 72E9DC 802A14AC 00431021 */  addu      $v0, $v0, $v1
/* 72E9E0 802A14B0 8043001B */  lb        $v1, 0x1b($v0)
/* 72E9E4 802A14B4 AE0300B0 */  sw        $v1, 0xb0($s0)
/* 72E9E8 802A14B8 8044001C */  lb        $a0, 0x1c($v0)
/* 72E9EC 802A14BC 0000102D */  daddu     $v0, $zero, $zero
/* 72E9F0 802A14C0 04600005 */  bltz      $v1, .L802A14D8
/* 72E9F4 802A14C4 AE0400B4 */   sw       $a0, 0xb4($s0)
/* 72E9F8 802A14C8 5C600005 */  bgtzl     $v1, .L802A14E0
/* 72E9FC 802A14CC AE0200C0 */   sw       $v0, 0xc0($s0)
/* 72EA00 802A14D0 04830003 */  bgezl     $a0, .L802A14E0
/* 72EA04 802A14D4 AE0200C0 */   sw       $v0, 0xc0($s0)
.L802A14D8:
/* 72EA08 802A14D8 24020001 */  addiu     $v0, $zero, 1
/* 72EA0C 802A14DC AE0200C0 */  sw        $v0, 0xc0($s0)
.L802A14E0:
/* 72EA10 802A14E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 72EA14 802A14E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 72EA18 802A14E8 24020002 */  addiu     $v0, $zero, 2
/* 72EA1C 802A14EC 03E00008 */  jr        $ra
