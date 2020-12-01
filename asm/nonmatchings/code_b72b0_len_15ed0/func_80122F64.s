.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80122F64
/* B9664 80122F64 2402F7FF */  addiu     $v0, $zero, -0x801
/* B9668 80122F68 00822024 */  and       $a0, $a0, $v0
/* B966C 80122F6C 3C028015 */  lui       $v0, %hi(D_80154370)
/* B9670 80122F70 8C424370 */  lw        $v0, %lo(D_80154370)($v0)
/* B9674 80122F74 00042080 */  sll       $a0, $a0, 2
/* B9678 80122F78 00822021 */  addu      $a0, $a0, $v0
/* B967C 80122F7C 8C820000 */  lw        $v0, ($a0)
/* B9680 80122F80 AC460060 */  sw        $a2, 0x60($v0)
/* B9684 80122F84 03E00008 */  jr        $ra
/* B9688 80122F88 AC450064 */   sw       $a1, 0x64($v0)
