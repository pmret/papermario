.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D3F74
/* F8924 802D3F74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F8928 802D3F78 AFBF0014 */  sw        $ra, 0x14($sp)
/* F892C 802D3F7C AFB00010 */  sw        $s0, 0x10($sp)
/* F8930 802D3F80 8C90000C */  lw        $s0, 0xc($a0)
/* F8934 802D3F84 8E050000 */  lw        $a1, ($s0)
/* F8938 802D3F88 0C0B1EAF */  jal       get_variable
/* F893C 802D3F8C 26100004 */   addiu    $s0, $s0, 4
/* F8940 802D3F90 3C03802E */  lui       $v1, %hi(D_802DB7C0)
/* F8944 802D3F94 8C63B7C0 */  lw        $v1, %lo(D_802DB7C0)($v1)
/* F8948 802D3F98 00021080 */  sll       $v0, $v0, 2
/* F894C 802D3F9C 00431021 */  addu      $v0, $v0, $v1
/* F8950 802D3FA0 8C420000 */  lw        $v0, ($v0)
/* F8954 802D3FA4 8C440000 */  lw        $a0, ($v0)
/* F8958 802D3FA8 0C048B77 */  jal       get_entity_model
/* F895C 802D3FAC 8E100000 */   lw       $s0, ($s0)
/* F8960 802D3FB0 AC500000 */  sw        $s0, ($v0)
/* F8964 802D3FB4 8FBF0014 */  lw        $ra, 0x14($sp)
/* F8968 802D3FB8 8FB00010 */  lw        $s0, 0x10($sp)
/* F896C 802D3FBC 24020002 */  addiu     $v0, $zero, 2
/* F8970 802D3FC0 03E00008 */  jr        $ra
/* F8974 802D3FC4 27BD0018 */   addiu    $sp, $sp, 0x18
