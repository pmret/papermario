.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B79C8_E20AD8
/* E20AD8 802B79C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E20ADC 802B79CC AFBF0010 */  sw        $ra, 0x10($sp)
/* E20AE0 802B79D0 0C0ADD7A */  jal       func_802B75E8_E206F8
/* E20AE4 802B79D4 00000000 */   nop      
/* E20AE8 802B79D8 3C04800F */  lui       $a0, %hi(gPlayerStatusPtr)
/* E20AEC 802B79DC 8C847B30 */  lw        $a0, %lo(gPlayerStatusPtr)($a0)
/* E20AF0 802B79E0 2402FFFF */  addiu     $v0, $zero, -1
/* E20AF4 802B79E4 A48200C6 */  sh        $v0, 0xc6($a0)
/* E20AF8 802B79E8 8C820004 */  lw        $v0, 4($a0)
/* E20AFC 802B79EC 2403FFEF */  addiu     $v1, $zero, -0x11
/* E20B00 802B79F0 3C018011 */  lui       $at, %hi(D_8010C958)
/* E20B04 802B79F4 AC20C958 */  sw        $zero, %lo(D_8010C958)($at)
/* E20B08 802B79F8 AC8000C8 */  sw        $zero, 0xc8($a0)
/* E20B0C 802B79FC 00431024 */  and       $v0, $v0, $v1
/* E20B10 802B7A00 AC820004 */  sw        $v0, 4($a0)
/* E20B14 802B7A04 0C03BCF5 */  jal       func_800EF3D4
/* E20B18 802B7A08 0000202D */   daddu    $a0, $zero, $zero
/* E20B1C 802B7A0C 0C03BCE9 */  jal       func_800EF3A4
/* E20B20 802B7A10 00000000 */   nop      
/* E20B24 802B7A14 8FBF0010 */  lw        $ra, 0x10($sp)
/* E20B28 802B7A18 03E00008 */  jr        $ra
/* E20B2C 802B7A1C 27BD0018 */   addiu    $sp, $sp, 0x18
