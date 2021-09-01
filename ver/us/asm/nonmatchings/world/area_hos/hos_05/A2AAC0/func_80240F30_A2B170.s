.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F30_A2B170
/* A2B170 80240F30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2B174 80240F34 3C05F4AC */  lui       $a1, 0xf4ac
/* A2B178 80240F38 AFBF0010 */  sw        $ra, 0x10($sp)
/* A2B17C 80240F3C 0C0B1EAF */  jal       evt_get_variable
/* A2B180 80240F40 34A5D480 */   ori      $a1, $a1, 0xd480
/* A2B184 80240F44 3C058025 */  lui       $a1, %hi(D_802495DC_A3381C)
/* A2B188 80240F48 24A595DC */  addiu     $a1, $a1, %lo(D_802495DC_A3381C)
/* A2B18C 80240F4C 8CA40000 */  lw        $a0, ($a1)
/* A2B190 80240F50 8C42000C */  lw        $v0, 0xc($v0)
/* A2B194 80240F54 00041840 */  sll       $v1, $a0, 1
/* A2B198 80240F58 00641821 */  addu      $v1, $v1, $a0
/* A2B19C 80240F5C 00031900 */  sll       $v1, $v1, 4
/* A2B1A0 80240F60 00621821 */  addu      $v1, $v1, $v0
/* A2B1A4 80240F64 24020001 */  addiu     $v0, $zero, 1
/* A2B1A8 80240F68 A0620059 */  sb        $v0, 0x59($v1)
/* A2B1AC 80240F6C 8CA30000 */  lw        $v1, ($a1)
/* A2B1B0 80240F70 24630001 */  addiu     $v1, $v1, 1
/* A2B1B4 80240F74 ACA30000 */  sw        $v1, ($a1)
/* A2B1B8 80240F78 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2B1BC 80240F7C 24020002 */  addiu     $v0, $zero, 2
/* A2B1C0 80240F80 03E00008 */  jr        $ra
/* A2B1C4 80240F84 27BD0018 */   addiu    $sp, $sp, 0x18
