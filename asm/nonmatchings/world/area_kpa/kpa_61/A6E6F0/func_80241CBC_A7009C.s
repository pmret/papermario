.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CBC_A7009C
/* A7009C 80241CBC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A700A0 80241CC0 AFB10014 */  sw        $s1, 0x14($sp)
/* A700A4 80241CC4 0080882D */  daddu     $s1, $a0, $zero
/* A700A8 80241CC8 AFBF0018 */  sw        $ra, 0x18($sp)
/* A700AC 80241CCC AFB00010 */  sw        $s0, 0x10($sp)
/* A700B0 80241CD0 8E300148 */  lw        $s0, 0x148($s1)
/* A700B4 80241CD4 0C00EABB */  jal       get_npc_unsafe
/* A700B8 80241CD8 86040008 */   lh       $a0, 8($s0)
/* A700BC 80241CDC 0040202D */  daddu     $a0, $v0, $zero
/* A700C0 80241CE0 9482008E */  lhu       $v0, 0x8e($a0)
/* A700C4 80241CE4 2442FFFF */  addiu     $v0, $v0, -1
/* A700C8 80241CE8 A482008E */  sh        $v0, 0x8e($a0)
/* A700CC 80241CEC 00021400 */  sll       $v0, $v0, 0x10
/* A700D0 80241CF0 1C400008 */  bgtz      $v0, .L80241D14
/* A700D4 80241CF4 00000000 */   nop      
/* A700D8 80241CF8 8E0200CC */  lw        $v0, 0xcc($s0)
/* A700DC 80241CFC 8C430024 */  lw        $v1, 0x24($v0)
/* A700E0 80241D00 24020007 */  addiu     $v0, $zero, 7
/* A700E4 80241D04 A482008E */  sh        $v0, 0x8e($a0)
/* A700E8 80241D08 24020017 */  addiu     $v0, $zero, 0x17
/* A700EC 80241D0C AC830028 */  sw        $v1, 0x28($a0)
/* A700F0 80241D10 AE220070 */  sw        $v0, 0x70($s1)
.L80241D14:
/* A700F4 80241D14 8FBF0018 */  lw        $ra, 0x18($sp)
/* A700F8 80241D18 8FB10014 */  lw        $s1, 0x14($sp)
/* A700FC 80241D1C 8FB00010 */  lw        $s0, 0x10($sp)
/* A70100 80241D20 03E00008 */  jr        $ra
/* A70104 80241D24 27BD0020 */   addiu    $sp, $sp, 0x20
