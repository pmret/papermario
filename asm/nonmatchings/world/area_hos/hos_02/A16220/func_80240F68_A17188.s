.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F68_A17188
/* A17188 80240F68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1718C 80240F6C AFBF0010 */  sw        $ra, 0x10($sp)
/* A17190 80240F70 8C82000C */  lw        $v0, 0xc($a0)
/* A17194 80240F74 0C0B1EAF */  jal       get_variable
/* A17198 80240F78 8C450000 */   lw       $a1, ($v0)
/* A1719C 80240F7C 0040182D */  daddu     $v1, $v0, $zero
/* A171A0 80240F80 8C62000C */  lw        $v0, 0xc($v1)
/* A171A4 80240F84 3C01432A */  lui       $at, 0x432a
/* A171A8 80240F88 44810000 */  mtc1      $at, $f0
/* A171AC 80240F8C 00000000 */  nop
/* A171B0 80240F90 E4400078 */  swc1      $f0, 0x78($v0)
/* A171B4 80240F94 8C62000C */  lw        $v0, 0xc($v1)
/* A171B8 80240F98 E440007C */  swc1      $f0, 0x7c($v0)
/* A171BC 80240F9C 8C64000C */  lw        $a0, 0xc($v1)
/* A171C0 80240FA0 3C014000 */  lui       $at, 0x4000
/* A171C4 80240FA4 44810000 */  mtc1      $at, $f0
/* A171C8 80240FA8 00000000 */  nop
/* A171CC 80240FAC E4800068 */  swc1      $f0, 0x68($a0)
/* A171D0 80240FB0 8C64000C */  lw        $a0, 0xc($v1)
/* A171D4 80240FB4 240300FF */  addiu     $v1, $zero, 0xff
/* A171D8 80240FB8 AC830038 */  sw        $v1, 0x38($a0)
/* A171DC 80240FBC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A171E0 80240FC0 24020002 */  addiu     $v0, $zero, 2
/* A171E4 80240FC4 03E00008 */  jr        $ra
/* A171E8 80240FC8 27BD0018 */   addiu    $sp, $sp, 0x18
/* A171EC 80240FCC 00000000 */  nop
