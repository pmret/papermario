.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024120C_D3B7DC
/* D3B7DC 8024120C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3B7E0 80241210 AFBF0010 */  sw        $ra, 0x10($sp)
/* D3B7E4 80241214 8C82000C */  lw        $v0, 0xc($a0)
/* D3B7E8 80241218 0C0B1EAF */  jal       evt_get_variable
/* D3B7EC 8024121C 8C450000 */   lw       $a1, ($v0)
/* D3B7F0 80241220 3C038025 */  lui       $v1, %hi(D_80251470)
/* D3B7F4 80241224 8C631470 */  lw        $v1, %lo(D_80251470)($v1)
/* D3B7F8 80241228 8C63000C */  lw        $v1, 0xc($v1)
/* D3B7FC 8024122C AC620034 */  sw        $v0, 0x34($v1)
/* D3B800 80241230 8FBF0010 */  lw        $ra, 0x10($sp)
/* D3B804 80241234 24020002 */  addiu     $v0, $zero, 2
/* D3B808 80241238 03E00008 */  jr        $ra
/* D3B80C 8024123C 27BD0018 */   addiu    $sp, $sp, 0x18
