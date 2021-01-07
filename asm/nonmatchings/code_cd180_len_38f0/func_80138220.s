.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80138220
/* CE920 80138220 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CE924 80138224 3C048015 */  lui       $a0, %hi(D_80156908)
/* CE928 80138228 24846908 */  addiu     $a0, $a0, %lo(D_80156908)
/* CE92C 8013822C AFBF0010 */  sw        $ra, 0x10($sp)
/* CE930 80138230 8C830000 */  lw        $v1, ($a0)
/* CE934 80138234 2402FFFF */  addiu     $v0, $zero, -1
/* CE938 80138238 10620016 */  beq       $v1, $v0, .L80138294
/* CE93C 8013823C 00000000 */   nop      
/* CE940 80138240 3C018015 */  lui       $at, %hi(D_8015690C)
/* CE944 80138244 C422690C */  lwc1      $f2, %lo(D_8015690C)($at)
/* CE948 80138248 3C01BF80 */  lui       $at, 0xbf80
/* CE94C 8013824C 44810000 */  mtc1      $at, $f0
/* CE950 80138250 00000000 */  nop       
/* CE954 80138254 46001032 */  c.eq.s    $f2, $f0
/* CE958 80138258 00000000 */  nop       
/* CE95C 8013825C 4501000D */  bc1t      .L80138294
/* CE960 80138260 00000000 */   nop      
/* CE964 80138264 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* CE968 80138268 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* CE96C 8013826C 80430070 */  lb        $v1, 0x70($v0)
/* CE970 80138270 24020002 */  addiu     $v0, $zero, 2
/* CE974 80138274 10620007 */  beq       $v1, $v0, .L80138294
/* CE978 80138278 00000000 */   nop      
/* CE97C 8013827C 90840003 */  lbu       $a0, 3($a0)
/* CE980 80138280 44051000 */  mfc1      $a1, $f2
/* CE984 80138284 3C068016 */  lui       $a2, %hi(D_8015C7A8)
/* CE988 80138288 24C6C7A8 */  addiu     $a2, $a2, %lo(D_8015C7A8)
/* CE98C 8013828C 0C04DAA0 */  jal       func_80136A80
/* CE990 80138290 00000000 */   nop      
.L80138294:
/* CE994 80138294 8FBF0010 */  lw        $ra, 0x10($sp)
/* CE998 80138298 03E00008 */  jr        $ra
/* CE99C 8013829C 27BD0018 */   addiu    $sp, $sp, 0x18
