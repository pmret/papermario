.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801449DC
/* DB0DC 801449DC 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB0E0 801449E0 00822024 */  and       $a0, $a0, $v0
/* DB0E4 801449E4 3C028015 */  lui       $v0, %hi(D_80157960)
/* DB0E8 801449E8 8C427960 */  lw        $v0, %lo(D_80157960)($v0)
/* DB0EC 801449EC 00042080 */  sll       $a0, $a0, 2
/* DB0F0 801449F0 00822021 */  addu      $a0, $a0, $v0
/* DB0F4 801449F4 8C820000 */  lw        $v0, ($a0)
/* DB0F8 801449F8 03E00008 */  jr        $ra
/* DB0FC 801449FC A0450044 */   sb       $a1, 0x44($v0)
