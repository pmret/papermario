.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F88
/* A2B1C8 80240F88 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2B1CC 80240F8C 3C05F4AC */  lui       $a1, 0xf4ac
/* A2B1D0 80240F90 AFBF0010 */  sw        $ra, 0x10($sp)
/* A2B1D4 80240F94 0C0B1EAF */  jal       get_variable
/* A2B1D8 80240F98 34A5D480 */   ori      $a1, $a1, 0xd480
/* A2B1DC 80240F9C 3C058025 */  lui       $a1, 0x8025
/* A2B1E0 80240FA0 24A595E0 */  addiu     $a1, $a1, -0x6a20
/* A2B1E4 80240FA4 8CA40000 */  lw        $a0, ($a1)
/* A2B1E8 80240FA8 8C42000C */  lw        $v0, 0xc($v0)
/* A2B1EC 80240FAC 00041840 */  sll       $v1, $a0, 1
/* A2B1F0 80240FB0 00641821 */  addu      $v1, $v1, $a0
/* A2B1F4 80240FB4 00031900 */  sll       $v1, $v1, 4
/* A2B1F8 80240FB8 00621821 */  addu      $v1, $v1, $v0
/* A2B1FC 80240FBC 24020003 */  addiu     $v0, $zero, 3
/* A2B200 80240FC0 A0620059 */  sb        $v0, 0x59($v1)
/* A2B204 80240FC4 8CA30000 */  lw        $v1, ($a1)
/* A2B208 80240FC8 24630001 */  addiu     $v1, $v1, 1
/* A2B20C 80240FCC ACA30000 */  sw        $v1, ($a1)
/* A2B210 80240FD0 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2B214 80240FD4 24020002 */  addiu     $v0, $zero, 2
/* A2B218 80240FD8 03E00008 */  jr        $ra
/* A2B21C 80240FDC 27BD0018 */   addiu    $sp, $sp, 0x18
