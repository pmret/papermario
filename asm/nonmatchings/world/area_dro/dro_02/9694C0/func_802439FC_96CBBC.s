.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802439FC_96CBBC
/* 96CBBC 802439FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96CBC0 80243A00 AFB00010 */  sw        $s0, 0x10($sp)
/* 96CBC4 80243A04 0080802D */  daddu     $s0, $a0, $zero
/* 96CBC8 80243A08 AFBF0014 */  sw        $ra, 0x14($sp)
/* 96CBCC 80243A0C 0C00EABB */  jal       get_npc_unsafe
/* 96CBD0 80243A10 8E04008C */   lw       $a0, 0x8c($s0)
/* 96CBD4 80243A14 0040282D */  daddu     $a1, $v0, $zero
/* 96CBD8 80243A18 8E040094 */  lw        $a0, 0x94($s0)
/* 96CBDC 80243A1C 8CA30028 */  lw        $v1, 0x28($a1)
/* 96CBE0 80243A20 ACA40028 */  sw        $a0, 0x28($a1)
/* 96CBE4 80243A24 8FBF0014 */  lw        $ra, 0x14($sp)
/* 96CBE8 80243A28 8FB00010 */  lw        $s0, 0x10($sp)
/* 96CBEC 80243A2C 24020002 */  addiu     $v0, $zero, 2
/* 96CBF0 80243A30 3C018025 */  lui       $at, 0x8025
/* 96CBF4 80243A34 AC23F3B8 */  sw        $v1, -0xc48($at)
/* 96CBF8 80243A38 03E00008 */  jr        $ra
/* 96CBFC 80243A3C 27BD0018 */   addiu    $sp, $sp, 0x18
