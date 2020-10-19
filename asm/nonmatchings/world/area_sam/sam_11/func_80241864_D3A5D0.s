.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241864_D3BE34
/* D3BE34 80241864 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3BE38 80241868 AFB00010 */  sw        $s0, 0x10($sp)
/* D3BE3C 8024186C 0080802D */  daddu     $s0, $a0, $zero
/* D3BE40 80241870 AFBF0014 */  sw        $ra, 0x14($sp)
/* D3BE44 80241874 0C00EAD2 */  jal       get_npc_safe
/* D3BE48 80241878 24040001 */   addiu    $a0, $zero, 1
/* D3BE4C 8024187C 3C0143EB */  lui       $at, 0x43eb
/* D3BE50 80241880 44811000 */  mtc1      $at, $f2
/* D3BE54 80241884 3C0140A0 */  lui       $at, 0x40a0
/* D3BE58 80241888 44810000 */  mtc1      $at, $f0
/* D3BE5C 8024188C 0040182D */  daddu     $v1, $v0, $zero
/* D3BE60 80241890 AC60003C */  sw        $zero, 0x3c($v1)
/* D3BE64 80241894 E4620038 */  swc1      $f2, 0x38($v1)
/* D3BE68 80241898 E4600040 */  swc1      $f0, 0x40($v1)
/* D3BE6C 8024189C E60000AC */  swc1      $f0, 0xac($s0)
/* D3BE70 802418A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* D3BE74 802418A4 8FB00010 */  lw        $s0, 0x10($sp)
/* D3BE78 802418A8 24020002 */  addiu     $v0, $zero, 2
/* D3BE7C 802418AC 03E00008 */  jr        $ra
/* D3BE80 802418B0 27BD0018 */   addiu    $sp, $sp, 0x18
