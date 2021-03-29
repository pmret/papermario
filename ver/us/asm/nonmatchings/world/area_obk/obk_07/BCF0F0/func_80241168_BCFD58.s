.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241168_BCFD58
/* BCFD58 80241168 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BCFD5C 8024116C AFBF0018 */  sw        $ra, 0x18($sp)
/* BCFD60 80241170 AFB10014 */  sw        $s1, 0x14($sp)
/* BCFD64 80241174 0C090150 */  jal       func_80240540_BCF130
/* BCFD68 80241178 AFB00010 */   sw       $s0, 0x10($sp)
/* BCFD6C 8024117C 3C048024 */  lui       $a0, %hi(func_80240A6C_BCF65C)
/* BCFD70 80241180 24840A6C */  addiu     $a0, $a0, %lo(func_80240A6C_BCF65C)
/* BCFD74 80241184 3C06800A */  lui       $a2, %hi(gOverrideFlags)
/* BCFD78 80241188 24C6A650 */  addiu     $a2, $a2, %lo(gOverrideFlags)
/* BCFD7C 8024118C 3C058024 */  lui       $a1, %hi(func_802410C0_BCFCB0)
/* BCFD80 80241190 24A510C0 */  addiu     $a1, $a1, %lo(func_802410C0_BCFCB0)
/* BCFD84 80241194 8CC30000 */  lw        $v1, ($a2)
/* BCFD88 80241198 0040882D */  daddu     $s1, $v0, $zero
/* BCFD8C 8024119C 34630010 */  ori       $v1, $v1, 0x10
/* BCFD90 802411A0 0C048C8F */  jal       bind_dynamic_entity_7
/* BCFD94 802411A4 ACC30000 */   sw       $v1, ($a2)
/* BCFD98 802411A8 24040059 */  addiu     $a0, $zero, 0x59
/* BCFD9C 802411AC 26230164 */  addiu     $v1, $s1, 0x164
/* BCFDA0 802411B0 AE22002C */  sw        $v0, 0x2c($s1)
/* BCFDA4 802411B4 24020014 */  addiu     $v0, $zero, 0x14
/* BCFDA8 802411B8 AE220014 */  sw        $v0, 0x14($s1)
/* BCFDAC 802411BC 24020028 */  addiu     $v0, $zero, 0x28
/* BCFDB0 802411C0 AE220018 */  sw        $v0, 0x18($s1)
/* BCFDB4 802411C4 2402003C */  addiu     $v0, $zero, 0x3c
/* BCFDB8 802411C8 AE22001C */  sw        $v0, 0x1c($s1)
/* BCFDBC 802411CC 24020050 */  addiu     $v0, $zero, 0x50
/* BCFDC0 802411D0 AE220020 */  sw        $v0, 0x20($s1)
/* BCFDC4 802411D4 24020064 */  addiu     $v0, $zero, 0x64
/* BCFDC8 802411D8 AE220024 */  sw        $v0, 0x24($s1)
/* BCFDCC 802411DC 24020005 */  addiu     $v0, $zero, 5
/* BCFDD0 802411E0 AE200030 */  sw        $zero, 0x30($s1)
/* BCFDD4 802411E4 AE200004 */  sw        $zero, 4($s1)
/* BCFDD8 802411E8 AE200008 */  sw        $zero, 8($s1)
/* BCFDDC 802411EC AE200010 */  sw        $zero, 0x10($s1)
/* BCFDE0 802411F0 AE220028 */  sw        $v0, 0x28($s1)
.L802411F4:
/* BCFDE4 802411F4 AC600058 */  sw        $zero, 0x58($v1)
/* BCFDE8 802411F8 2484FFFF */  addiu     $a0, $a0, -1
/* BCFDEC 802411FC 0481FFFD */  bgez      $a0, .L802411F4
/* BCFDF0 80241200 2463FFFC */   addiu    $v1, $v1, -4
/* BCFDF4 80241204 3C048011 */  lui       $a0, %hi(D_80108B28)
/* BCFDF8 80241208 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* BCFDFC 8024120C 3C013F80 */  lui       $at, 0x3f80
/* BCFE00 80241210 44810000 */  mtc1      $at, $f0
/* BCFE04 80241214 2402FFD0 */  addiu     $v0, $zero, -0x30
/* BCFE08 80241218 AE220034 */  sw        $v0, 0x34($s1)
/* BCFE0C 8024121C 24020040 */  addiu     $v0, $zero, 0x40
/* BCFE10 80241220 AE2001C0 */  sw        $zero, 0x1c0($s1)
/* BCFE14 80241224 AE2001C8 */  sw        $zero, 0x1c8($s1)
/* BCFE18 80241228 AE2001CC */  sw        $zero, 0x1cc($s1)
/* BCFE1C 8024122C AE220038 */  sw        $v0, 0x38($s1)
/* BCFE20 80241230 E62001C4 */  swc1      $f0, 0x1c4($s1)
/* BCFE24 80241234 0C050529 */  jal       create_icon
/* BCFE28 80241238 E62001D0 */   swc1     $f0, 0x1d0($s1)
/* BCFE2C 8024123C 0040802D */  daddu     $s0, $v0, $zero
/* BCFE30 80241240 8E250034 */  lw        $a1, 0x34($s1)
/* BCFE34 80241244 8E260038 */  lw        $a2, 0x38($s1)
/* BCFE38 80241248 0200202D */  daddu     $a0, $s0, $zero
/* BCFE3C 8024124C 0C051261 */  jal       set_icon_render_pos
/* BCFE40 80241250 AE30003C */   sw       $s0, 0x3c($s1)
/* BCFE44 80241254 0200202D */  daddu     $a0, $s0, $zero
/* BCFE48 80241258 0C051277 */  jal       func_801449DC
/* BCFE4C 8024125C 0000282D */   daddu    $a1, $zero, $zero
/* BCFE50 80241260 0200202D */  daddu     $a0, $s0, $zero
/* BCFE54 80241264 0C051280 */  jal       set_icon_flags
/* BCFE58 80241268 24050082 */   addiu    $a1, $zero, 0x82
/* BCFE5C 8024126C 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* BCFE60 80241270 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* BCFE64 80241274 0C050529 */  jal       create_icon
/* BCFE68 80241278 00000000 */   nop
/* BCFE6C 8024127C 0040802D */  daddu     $s0, $v0, $zero
/* BCFE70 80241280 8E250034 */  lw        $a1, 0x34($s1)
/* BCFE74 80241284 8E260038 */  lw        $a2, 0x38($s1)
/* BCFE78 80241288 0200202D */  daddu     $a0, $s0, $zero
/* BCFE7C 8024128C AE300040 */  sw        $s0, 0x40($s1)
/* BCFE80 80241290 0C051261 */  jal       set_icon_render_pos
/* BCFE84 80241294 24C6001C */   addiu    $a2, $a2, 0x1c
/* BCFE88 80241298 0200202D */  daddu     $a0, $s0, $zero
/* BCFE8C 8024129C 0C051277 */  jal       func_801449DC
/* BCFE90 802412A0 0000282D */   daddu    $a1, $zero, $zero
/* BCFE94 802412A4 0200202D */  daddu     $a0, $s0, $zero
/* BCFE98 802412A8 0C051280 */  jal       set_icon_flags
/* BCFE9C 802412AC 24050082 */   addiu    $a1, $zero, 0x82
/* BCFEA0 802412B0 3C048011 */  lui       $a0, %hi(D_80109244)
/* BCFEA4 802412B4 24849244 */  addiu     $a0, $a0, %lo(D_80109244)
/* BCFEA8 802412B8 0C050529 */  jal       create_icon
/* BCFEAC 802412BC 00000000 */   nop
/* BCFEB0 802412C0 0040802D */  daddu     $s0, $v0, $zero
/* BCFEB4 802412C4 8E250034 */  lw        $a1, 0x34($s1)
/* BCFEB8 802412C8 8E260038 */  lw        $a2, 0x38($s1)
/* BCFEBC 802412CC 0200202D */  daddu     $a0, $s0, $zero
/* BCFEC0 802412D0 AE300044 */  sw        $s0, 0x44($s1)
/* BCFEC4 802412D4 0C051261 */  jal       set_icon_render_pos
/* BCFEC8 802412D8 24C6001C */   addiu    $a2, $a2, 0x1c
/* BCFECC 802412DC 0200202D */  daddu     $a0, $s0, $zero
/* BCFED0 802412E0 0C051277 */  jal       func_801449DC
/* BCFED4 802412E4 0000282D */   daddu    $a1, $zero, $zero
/* BCFED8 802412E8 0200202D */  daddu     $a0, $s0, $zero
/* BCFEDC 802412EC 0C051280 */  jal       set_icon_flags
/* BCFEE0 802412F0 24050082 */   addiu    $a1, $zero, 0x82
/* BCFEE4 802412F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* BCFEE8 802412F8 8FB10014 */  lw        $s1, 0x14($sp)
/* BCFEEC 802412FC 8FB00010 */  lw        $s0, 0x10($sp)
/* BCFEF0 80241300 24020002 */  addiu     $v0, $zero, 2
/* BCFEF4 80241304 03E00008 */  jr        $ra
/* BCFEF8 80241308 27BD0020 */   addiu    $sp, $sp, 0x20
