.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F4C_DB420C
/* DB420C 80241F4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DB4210 80241F50 AFB10014 */  sw        $s1, 0x14($sp)
/* DB4214 80241F54 0080882D */  daddu     $s1, $a0, $zero
/* DB4218 80241F58 AFBF0018 */  sw        $ra, 0x18($sp)
/* DB421C 80241F5C AFB00010 */  sw        $s0, 0x10($sp)
/* DB4220 80241F60 8E30000C */  lw        $s0, 0xc($s1)
/* DB4224 80241F64 8E050000 */  lw        $a1, ($s0)
/* DB4228 80241F68 0C0B1EAF */  jal       get_variable
/* DB422C 80241F6C 26100004 */   addiu    $s0, $s0, 4
/* DB4230 80241F70 0C00EAD2 */  jal       get_npc_safe
/* DB4234 80241F74 0040202D */   daddu    $a0, $v0, $zero
/* DB4238 80241F78 10400005 */  beqz      $v0, .L80241F90
/* DB423C 80241F7C 00000000 */   nop      
/* DB4240 80241F80 8E050000 */  lw        $a1, ($s0)
/* DB4244 80241F84 844600A8 */  lh        $a2, 0xa8($v0)
/* DB4248 80241F88 0C0B2026 */  jal       set_variable
/* DB424C 80241F8C 0220202D */   daddu    $a0, $s1, $zero
.L80241F90:
/* DB4250 80241F90 8FBF0018 */  lw        $ra, 0x18($sp)
/* DB4254 80241F94 8FB10014 */  lw        $s1, 0x14($sp)
/* DB4258 80241F98 8FB00010 */  lw        $s0, 0x10($sp)
/* DB425C 80241F9C 24020002 */  addiu     $v0, $zero, 2
/* DB4260 80241FA0 03E00008 */  jr        $ra
/* DB4264 80241FA4 27BD0020 */   addiu    $sp, $sp, 0x20
