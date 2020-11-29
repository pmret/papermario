.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1204
/* 102A84 802E1204 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102A88 802E1208 AFB00010 */  sw        $s0, 0x10($sp)
/* 102A8C 802E120C 0080802D */  daddu     $s0, $a0, $zero
/* 102A90 802E1210 3C04F840 */  lui       $a0, 0xf840
/* 102A94 802E1214 AFBF0014 */  sw        $ra, 0x14($sp)
/* 102A98 802E1218 0C05152F */  jal       get_global_flag
/* 102A9C 802E121C 34845BDF */   ori      $a0, $a0, 0x5bdf
/* 102AA0 802E1220 1440000B */  bnez      $v0, .L802E1250
/* 102AA4 802E1224 00000000 */   nop      
/* 102AA8 802E1228 3C05802F */  lui       $a1, %hi(D_802EB390)
/* 102AAC 802E122C 24A5B390 */  addiu     $a1, $a1, %lo(D_802EB390)
/* 102AB0 802E1230 ACA00000 */  sw        $zero, ($a1)
/* 102AB4 802E1234 0C049640 */  jal       load_string
/* 102AB8 802E1238 3C04001D */   lui      $a0, 0x1d
/* 102ABC 802E123C 3C04F840 */  lui       $a0, 0xf840
/* 102AC0 802E1240 0C051514 */  jal       set_global_flag
/* 102AC4 802E1244 34845BDF */   ori      $a0, $a0, 0x5bdf
/* 102AC8 802E1248 080B8498 */  j         .L802E1260
/* 102ACC 802E124C 00000000 */   nop      
.L802E1250:
/* 102AD0 802E1250 0C043F5A */  jal       func_8010FD68
/* 102AD4 802E1254 0200202D */   daddu    $a0, $s0, $zero
/* 102AD8 802E1258 0C043F5A */  jal       func_8010FD68
/* 102ADC 802E125C 0200202D */   daddu    $a0, $s0, $zero
.L802E1260:
/* 102AE0 802E1260 8FBF0014 */  lw        $ra, 0x14($sp)
/* 102AE4 802E1264 8FB00010 */  lw        $s0, 0x10($sp)
/* 102AE8 802E1268 03E00008 */  jr        $ra
/* 102AEC 802E126C 27BD0018 */   addiu    $sp, $sp, 0x18
