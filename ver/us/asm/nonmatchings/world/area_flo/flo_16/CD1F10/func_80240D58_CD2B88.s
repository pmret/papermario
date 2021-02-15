.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D58_CD2B88
/* CD2B88 80240D58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD2B8C 80240D5C AFBF0018 */  sw        $ra, 0x18($sp)
/* CD2B90 80240D60 0C00EAD2 */  jal       get_npc_safe
/* CD2B94 80240D64 2404FFFC */   addiu    $a0, $zero, -4
/* CD2B98 80240D68 3C0141F0 */  lui       $at, 0x41f0
/* CD2B9C 80240D6C 44810000 */  mtc1      $at, $f0
/* CD2BA0 80240D70 C442003C */  lwc1      $f2, 0x3c($v0)
/* CD2BA4 80240D74 46001080 */  add.s     $f2, $f2, $f0
/* CD2BA8 80240D78 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD2BAC 80240D7C 8C450038 */  lw        $a1, 0x38($v0)
/* CD2BB0 80240D80 8C470040 */  lw        $a3, 0x40($v0)
/* CD2BB4 80240D84 44061000 */  mfc1      $a2, $f2
/* CD2BB8 80240D88 0C01BFBC */  jal       func_8006FEF0
/* CD2BBC 80240D8C 24040002 */   addiu    $a0, $zero, 2
/* CD2BC0 80240D90 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD2BC4 80240D94 24020002 */  addiu     $v0, $zero, 2
/* CD2BC8 80240D98 03E00008 */  jr        $ra
/* CD2BCC 80240D9C 27BD0020 */   addiu    $sp, $sp, 0x20
