.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CD4_DE3164
/* DE3164 80240CD4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DE3168 80240CD8 AFB10014 */  sw        $s1, 0x14($sp)
/* DE316C 80240CDC 0080882D */  daddu     $s1, $a0, $zero
/* DE3170 80240CE0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DE3174 80240CE4 AFB00010 */  sw        $s0, 0x10($sp)
/* DE3178 80240CE8 8E30000C */  lw        $s0, 0xc($s1)
/* DE317C 80240CEC 8E050000 */  lw        $a1, ($s0)
/* DE3180 80240CF0 0C0B1EAF */  jal       get_variable
/* DE3184 80240CF4 26100004 */   addiu    $s0, $s0, 4
/* DE3188 80240CF8 0C00EAD2 */  jal       get_npc_safe
/* DE318C 80240CFC 0040202D */   daddu    $a0, $v0, $zero
/* DE3190 80240D00 10400005 */  beqz      $v0, .L80240D18
/* DE3194 80240D04 00000000 */   nop      
/* DE3198 80240D08 8E050000 */  lw        $a1, ($s0)
/* DE319C 80240D0C 844600A8 */  lh        $a2, 0xa8($v0)
/* DE31A0 80240D10 0C0B2026 */  jal       set_variable
/* DE31A4 80240D14 0220202D */   daddu    $a0, $s1, $zero
.L80240D18:
/* DE31A8 80240D18 8FBF0018 */  lw        $ra, 0x18($sp)
/* DE31AC 80240D1C 8FB10014 */  lw        $s1, 0x14($sp)
/* DE31B0 80240D20 8FB00010 */  lw        $s0, 0x10($sp)
/* DE31B4 80240D24 24020002 */  addiu     $v0, $zero, 2
/* DE31B8 80240D28 03E00008 */  jr        $ra
/* DE31BC 80240D2C 27BD0020 */   addiu    $sp, $sp, 0x20
