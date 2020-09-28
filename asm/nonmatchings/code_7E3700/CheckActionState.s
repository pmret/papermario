.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel CheckActionState
/* 7E405C 802831DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E4060 802831E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E4064 802831E4 0080802D */  daddu     $s0, $a0, $zero
/* 7E4068 802831E8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7E406C 802831EC AFB10014 */  sw        $s1, 0x14($sp)
/* 7E4070 802831F0 8E02000C */  lw        $v0, 0xc($s0)
/* 7E4074 802831F4 8C450004 */  lw        $a1, 4($v0)
/* 7E4078 802831F8 0C0B210B */  jal       get_float_variable
/* 7E407C 802831FC 8C510000 */   lw       $s1, ($v0)
/* 7E4080 80283200 0200202D */  daddu     $a0, $s0, $zero
/* 7E4084 80283204 0220282D */  daddu     $a1, $s1, $zero
/* 7E4088 80283208 3C068011 */  lui       $a2, %hi(gPlayerActionState)
/* 7E408C 8028320C 80C6F07C */  lb        $a2, %lo(gPlayerActionState)($a2)
/* 7E4090 80283210 4600008D */  trunc.w.s $f2, $f0
/* 7E4094 80283214 44021000 */  mfc1      $v0, $f2
/* 7E4098 80283218 00000000 */  nop       
/* 7E409C 8028321C 00C23026 */  xor       $a2, $a2, $v0
/* 7E40A0 80283220 0C0B2026 */  jal       set_variable
/* 7E40A4 80283224 2CC60001 */   sltiu    $a2, $a2, 1
/* 7E40A8 80283228 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7E40AC 8028322C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E40B0 80283230 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E40B4 80283234 24020002 */  addiu     $v0, $zero, 2
/* 7E40B8 80283238 03E00008 */  jr        $ra
/* 7E40BC 8028323C 27BD0020 */   addiu    $sp, $sp, 0x20
