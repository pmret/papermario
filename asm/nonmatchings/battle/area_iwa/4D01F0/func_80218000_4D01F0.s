.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_4D01F0
/* 4D01F0 80218000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4D01F4 80218004 AFB00010 */  sw        $s0, 0x10($sp)
/* 4D01F8 80218008 0080802D */  daddu     $s0, $a0, $zero
/* 4D01FC 8021800C AFBF0014 */  sw        $ra, 0x14($sp)
/* 4D0200 80218010 8E02000C */  lw        $v0, 0xc($s0)
/* 4D0204 80218014 0C0B1EAF */  jal       get_variable
/* 4D0208 80218018 8C450000 */   lw       $a1, ($v0)
/* 4D020C 8021801C 8E040148 */  lw        $a0, 0x148($s0)
/* 4D0210 80218020 0C09A75B */  jal       get_actor
/* 4D0214 80218024 0040802D */   daddu    $s0, $v0, $zero
/* 4D0218 80218028 16000005 */  bnez      $s0, .L80218040
/* 4D021C 8021802C 00000000 */   nop
/* 4D0220 80218030 8C430008 */  lw        $v1, 8($v0)
/* 4D0224 80218034 24020004 */  addiu     $v0, $zero, 4
/* 4D0228 80218038 08086012 */  j         .L80218048
/* 4D022C 8021803C A062001D */   sb       $v0, 0x1d($v1)
.L80218040:
/* 4D0230 80218040 8C420008 */  lw        $v0, 8($v0)
/* 4D0234 80218044 A040001D */  sb        $zero, 0x1d($v0)
.L80218048:
/* 4D0238 80218048 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4D023C 8021804C 8FB00010 */  lw        $s0, 0x10($sp)
/* 4D0240 80218050 24020002 */  addiu     $v0, $zero, 2
/* 4D0244 80218054 03E00008 */  jr        $ra
/* 4D0248 80218058 27BD0018 */   addiu    $sp, $sp, 0x18
