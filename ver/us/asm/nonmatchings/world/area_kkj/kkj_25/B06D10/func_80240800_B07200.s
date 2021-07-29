.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240800_B07200
/* B07200 80240800 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B07204 80240804 AFB10014 */  sw        $s1, 0x14($sp)
/* B07208 80240808 0080882D */  daddu     $s1, $a0, $zero
/* B0720C 8024080C 0000202D */  daddu     $a0, $zero, $zero
/* B07210 80240810 3C05FD05 */  lui       $a1, 0xfd05
/* B07214 80240814 34A50F8A */  ori       $a1, $a1, 0xf8a
/* B07218 80240818 AFBF0018 */  sw        $ra, 0x18($sp)
/* B0721C 8024081C 0C0B1EAF */  jal       get_variable
/* B07220 80240820 AFB00010 */   sw       $s0, 0x10($sp)
/* B07224 80240824 0040802D */  daddu     $s0, $v0, $zero
/* B07228 80240828 0C04EA15 */  jal       func_8013A854
/* B0722C 8024082C 8E040000 */   lw       $a0, ($s0)
/* B07230 80240830 0C048D70 */  jal       free_generic_entity
/* B07234 80240834 8E040004 */   lw       $a0, 4($s0)
/* B07238 80240838 0C00AB4B */  jal       heap_free
/* B0723C 8024083C 0200202D */   daddu    $a0, $s0, $zero
/* B07240 80240840 0220202D */  daddu     $a0, $s1, $zero
/* B07244 80240844 3C05FD05 */  lui       $a1, 0xfd05
/* B07248 80240848 34A50F8A */  ori       $a1, $a1, 0xf8a
/* B0724C 8024084C 0C0B2026 */  jal       set_variable
/* B07250 80240850 0000302D */   daddu    $a2, $zero, $zero
/* B07254 80240854 8FBF0018 */  lw        $ra, 0x18($sp)
/* B07258 80240858 8FB10014 */  lw        $s1, 0x14($sp)
/* B0725C 8024085C 8FB00010 */  lw        $s0, 0x10($sp)
/* B07260 80240860 24020002 */  addiu     $v0, $zero, 2
/* B07264 80240864 03E00008 */  jr        $ra
/* B07268 80240868 27BD0020 */   addiu    $sp, $sp, 0x20
