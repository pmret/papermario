.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A78_BA61F8
/* BA61F8 80241A78 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* BA61FC 80241A7C AFB10034 */  sw        $s1, 0x34($sp)
/* BA6200 80241A80 0080882D */  daddu     $s1, $a0, $zero
/* BA6204 80241A84 AFBF0038 */  sw        $ra, 0x38($sp)
/* BA6208 80241A88 AFB00030 */  sw        $s0, 0x30($sp)
/* BA620C 80241A8C 8E300148 */  lw        $s0, 0x148($s1)
/* BA6210 80241A90 0C00EABB */  jal       get_npc_unsafe
/* BA6214 80241A94 86040008 */   lh       $a0, 8($s0)
/* BA6218 80241A98 0040282D */  daddu     $a1, $v0, $zero
/* BA621C 80241A9C 94A2008E */  lhu       $v0, 0x8e($a1)
/* BA6220 80241AA0 24420001 */  addiu     $v0, $v0, 1
/* BA6224 80241AA4 A4A2008E */  sh        $v0, 0x8e($a1)
/* BA6228 80241AA8 00021400 */  sll       $v0, $v0, 0x10
/* BA622C 80241AAC 8E0300A0 */  lw        $v1, 0xa0($s0)
/* BA6230 80241AB0 00021403 */  sra       $v0, $v0, 0x10
/* BA6234 80241AB4 14430004 */  bne       $v0, $v1, .L80241AC8
/* BA6238 80241AB8 00000000 */   nop      
/* BA623C 80241ABC 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA6240 80241AC0 8C42002C */  lw        $v0, 0x2c($v0)
/* BA6244 80241AC4 ACA20028 */  sw        $v0, 0x28($a1)
.L80241AC8:
/* BA6248 80241AC8 84A3008E */  lh        $v1, 0x8e($a1)
/* BA624C 80241ACC 8E0200A4 */  lw        $v0, 0xa4($s0)
/* BA6250 80241AD0 14620002 */  bne       $v1, $v0, .L80241ADC
/* BA6254 80241AD4 24020003 */   addiu    $v0, $zero, 3
/* BA6258 80241AD8 AE02006C */  sw        $v0, 0x6c($s0)
.L80241ADC:
/* BA625C 80241ADC 84A2008E */  lh        $v0, 0x8e($a1)
/* BA6260 80241AE0 8E03009C */  lw        $v1, 0x9c($s0)
/* BA6264 80241AE4 0043102A */  slt       $v0, $v0, $v1
/* BA6268 80241AE8 1440001E */  bnez      $v0, .L80241B64
/* BA626C 80241AEC 24020004 */   addiu    $v0, $zero, 4
/* BA6270 80241AF0 AE02006C */  sw        $v0, 0x6c($s0)
/* BA6274 80241AF4 24020008 */  addiu     $v0, $zero, 8
/* BA6278 80241AF8 24040003 */  addiu     $a0, $zero, 3
/* BA627C 80241AFC A4A2008E */  sh        $v0, 0x8e($a1)
/* BA6280 80241B00 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA6284 80241B04 84A300A8 */  lh        $v1, 0xa8($a1)
/* BA6288 80241B08 3C013F80 */  lui       $at, 0x3f80
/* BA628C 80241B0C 44810000 */  mtc1      $at, $f0
/* BA6290 80241B10 3C014000 */  lui       $at, 0x4000
/* BA6294 80241B14 44811000 */  mtc1      $at, $f2
/* BA6298 80241B18 3C01C1A0 */  lui       $at, 0xc1a0
/* BA629C 80241B1C 44812000 */  mtc1      $at, $f4
/* BA62A0 80241B20 44833000 */  mtc1      $v1, $f6
/* BA62A4 80241B24 00000000 */  nop       
/* BA62A8 80241B28 468031A0 */  cvt.s.w   $f6, $f6
/* BA62AC 80241B2C 8C420000 */  lw        $v0, ($v0)
/* BA62B0 80241B30 44073000 */  mfc1      $a3, $f6
/* BA62B4 80241B34 0000302D */  daddu     $a2, $zero, $zero
/* BA62B8 80241B38 ACA20028 */  sw        $v0, 0x28($a1)
/* BA62BC 80241B3C 2402000A */  addiu     $v0, $zero, 0xa
/* BA62C0 80241B40 AFA2001C */  sw        $v0, 0x1c($sp)
/* BA62C4 80241B44 27A20028 */  addiu     $v0, $sp, 0x28
/* BA62C8 80241B48 E7A00010 */  swc1      $f0, 0x10($sp)
/* BA62CC 80241B4C E7A20014 */  swc1      $f2, 0x14($sp)
/* BA62D0 80241B50 E7A40018 */  swc1      $f4, 0x18($sp)
/* BA62D4 80241B54 0C01BFA4 */  jal       fx_emote
/* BA62D8 80241B58 AFA20020 */   sw       $v0, 0x20($sp)
/* BA62DC 80241B5C 2402000D */  addiu     $v0, $zero, 0xd
/* BA62E0 80241B60 AE220070 */  sw        $v0, 0x70($s1)
.L80241B64:
/* BA62E4 80241B64 8FBF0038 */  lw        $ra, 0x38($sp)
/* BA62E8 80241B68 8FB10034 */  lw        $s1, 0x34($sp)
/* BA62EC 80241B6C 8FB00030 */  lw        $s0, 0x30($sp)
/* BA62F0 80241B70 03E00008 */  jr        $ra
/* BA62F4 80241B74 27BD0040 */   addiu    $sp, $sp, 0x40
