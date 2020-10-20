.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DFC_A4A3BC
/* A4A3BC 80241DFC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A4A3C0 80241E00 AFBF0014 */  sw        $ra, 0x14($sp)
/* A4A3C4 80241E04 AFB00010 */  sw        $s0, 0x10($sp)
/* A4A3C8 80241E08 8C900148 */  lw        $s0, 0x148($a0)
/* A4A3CC 80241E0C 0C00EABB */  jal       get_npc_unsafe
/* A4A3D0 80241E10 86040008 */   lh       $a0, 8($s0)
/* A4A3D4 80241E14 0040202D */  daddu     $a0, $v0, $zero
/* A4A3D8 80241E18 8E03006C */  lw        $v1, 0x6c($s0)
/* A4A3DC 80241E1C 24020002 */  addiu     $v0, $zero, 2
/* A4A3E0 80241E20 14620003 */  bne       $v1, $v0, .L80241E30
/* A4A3E4 80241E24 00000000 */   nop      
/* A4A3E8 80241E28 AC80001C */  sw        $zero, 0x1c($a0)
/* A4A3EC 80241E2C AC800018 */  sw        $zero, 0x18($a0)
.L80241E30:
/* A4A3F0 80241E30 8FBF0014 */  lw        $ra, 0x14($sp)
/* A4A3F4 80241E34 8FB00010 */  lw        $s0, 0x10($sp)
/* A4A3F8 80241E38 24020002 */  addiu     $v0, $zero, 2
/* A4A3FC 80241E3C 03E00008 */  jr        $ra
/* A4A400 80241E40 27BD0018 */   addiu    $sp, $sp, 0x18
/* A4A404 80241E44 00000000 */  nop       
/* A4A408 80241E48 00000000 */  nop       
/* A4A40C 80241E4C 00000000 */  nop       
