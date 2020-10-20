.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024000C
/* BC2A9C 8024000C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC2AA0 80240010 AFB10014 */  sw        $s1, 0x14($sp)
/* BC2AA4 80240014 0080882D */  daddu     $s1, $a0, $zero
/* BC2AA8 80240018 AFBF0018 */  sw        $ra, 0x18($sp)
/* BC2AAC 8024001C AFB00010 */  sw        $s0, 0x10($sp)
/* BC2AB0 80240020 0C00EAD2 */  jal       get_npc_safe
/* BC2AB4 80240024 8E24014C */   lw       $a0, 0x14c($s1)
/* BC2AB8 80240028 0040802D */  daddu     $s0, $v0, $zero
/* BC2ABC 8024002C 8E230074 */  lw        $v1, 0x74($s1)
/* BC2AC0 80240030 24020001 */  addiu     $v0, $zero, 1
/* BC2AC4 80240034 10620036 */  beq       $v1, $v0, .L80240110
/* BC2AC8 80240038 28620002 */   slti     $v0, $v1, 2
/* BC2ACC 8024003C 10400005 */  beqz      $v0, .L80240054
/* BC2AD0 80240040 24020002 */   addiu    $v0, $zero, 2
/* BC2AD4 80240044 10600007 */  beqz      $v1, .L80240064
/* BC2AD8 80240048 00000000 */   nop      
/* BC2ADC 8024004C 0809005F */  j         .L8024017C
/* BC2AE0 80240050 00000000 */   nop      
.L80240054:
/* BC2AE4 80240054 10620036 */  beq       $v1, $v0, .L80240130
/* BC2AE8 80240058 00000000 */   nop      
/* BC2AEC 8024005C 0809005F */  j         .L8024017C
/* BC2AF0 80240060 00000000 */   nop      
.L80240064:
/* BC2AF4 80240064 0C00A67F */  jal       rand_int
/* BC2AF8 80240068 240400B4 */   addiu    $a0, $zero, 0xb4
/* BC2AFC 8024006C 24040032 */  addiu     $a0, $zero, 0x32
/* BC2B00 80240070 3C01C396 */  lui       $at, 0xc396
/* BC2B04 80240074 44810000 */  mtc1      $at, $f0
/* BC2B08 80240078 2442001E */  addiu     $v0, $v0, 0x1e
/* BC2B0C 8024007C A602008E */  sh        $v0, 0x8e($s0)
/* BC2B10 80240080 0C00A67F */  jal       rand_int
/* BC2B14 80240084 E6000040 */   swc1     $f0, 0x40($s0)
/* BC2B18 80240088 3C0142A0 */  lui       $at, 0x42a0
/* BC2B1C 8024008C 44811000 */  mtc1      $at, $f2
/* BC2B20 80240090 44820000 */  mtc1      $v0, $f0
/* BC2B24 80240094 00000000 */  nop       
/* BC2B28 80240098 46800020 */  cvt.s.w   $f0, $f0
/* BC2B2C 8024009C 46020000 */  add.s     $f0, $f0, $f2
/* BC2B30 802400A0 0C00A64D */  jal       func_80029934
/* BC2B34 802400A4 E600003C */   swc1     $f0, 0x3c($s0)
/* BC2B38 802400A8 46000000 */  add.s     $f0, $f0, $f0
/* BC2B3C 802400AC 3C014000 */  lui       $at, 0x4000
/* BC2B40 802400B0 44811000 */  mtc1      $at, $f2
/* BC2B44 802400B4 00000000 */  nop       
/* BC2B48 802400B8 46020000 */  add.s     $f0, $f0, $f2
/* BC2B4C 802400BC 24040064 */  addiu     $a0, $zero, 0x64
/* BC2B50 802400C0 0C00A67F */  jal       rand_int
/* BC2B54 802400C4 E6000018 */   swc1     $f0, 0x18($s0)
/* BC2B58 802400C8 28420032 */  slti      $v0, $v0, 0x32
/* BC2B5C 802400CC 10400007 */  beqz      $v0, .L802400EC
/* BC2B60 802400D0 00000000 */   nop      
/* BC2B64 802400D4 3C014387 */  lui       $at, 0x4387
/* BC2B68 802400D8 44810000 */  mtc1      $at, $f0
/* BC2B6C 802400DC 00000000 */  nop       
/* BC2B70 802400E0 E6000038 */  swc1      $f0, 0x38($s0)
/* BC2B74 802400E4 08090041 */  j         .L80240104
/* BC2B78 802400E8 E600000C */   swc1     $f0, 0xc($s0)
.L802400EC:
/* BC2B7C 802400EC 3C01C387 */  lui       $at, 0xc387
/* BC2B80 802400F0 44810000 */  mtc1      $at, $f0
/* BC2B84 802400F4 3C0142B4 */  lui       $at, 0x42b4
/* BC2B88 802400F8 44811000 */  mtc1      $at, $f2
/* BC2B8C 802400FC E6000038 */  swc1      $f0, 0x38($s0)
/* BC2B90 80240100 E602000C */  swc1      $f2, 0xc($s0)
.L80240104:
/* BC2B94 80240104 24020001 */  addiu     $v0, $zero, 1
/* BC2B98 80240108 0809005F */  j         .L8024017C
/* BC2B9C 8024010C AE220074 */   sw       $v0, 0x74($s1)
.L80240110:
/* BC2BA0 80240110 9602008E */  lhu       $v0, 0x8e($s0)
/* BC2BA4 80240114 2442FFFF */  addiu     $v0, $v0, -1
/* BC2BA8 80240118 A602008E */  sh        $v0, 0x8e($s0)
/* BC2BAC 8024011C 00021400 */  sll       $v0, $v0, 0x10
/* BC2BB0 80240120 14400016 */  bnez      $v0, .L8024017C
/* BC2BB4 80240124 24020002 */   addiu    $v0, $zero, 2
/* BC2BB8 80240128 0809005F */  j         .L8024017C
/* BC2BBC 8024012C AE220074 */   sw       $v0, 0x74($s1)
.L80240130:
/* BC2BC0 80240130 8E050018 */  lw        $a1, 0x18($s0)
/* BC2BC4 80240134 8E06000C */  lw        $a2, 0xc($s0)
/* BC2BC8 80240138 0C00EA95 */  jal       npc_move_heading
/* BC2BCC 8024013C 0200202D */   daddu    $a0, $s0, $zero
/* BC2BD0 80240140 C6020038 */  lwc1      $f2, 0x38($s0)
/* BC2BD4 80240144 3C01C38C */  lui       $at, 0xc38c
/* BC2BD8 80240148 44810000 */  mtc1      $at, $f0
/* BC2BDC 8024014C 00000000 */  nop       
/* BC2BE0 80240150 4600103C */  c.lt.s    $f2, $f0
/* BC2BE4 80240154 00000000 */  nop       
/* BC2BE8 80240158 45030008 */  bc1tl     .L8024017C
/* BC2BEC 8024015C AE200074 */   sw       $zero, 0x74($s1)
/* BC2BF0 80240160 3C01438C */  lui       $at, 0x438c
/* BC2BF4 80240164 44810000 */  mtc1      $at, $f0
/* BC2BF8 80240168 00000000 */  nop       
/* BC2BFC 8024016C 4602003C */  c.lt.s    $f0, $f2
/* BC2C00 80240170 00000000 */  nop       
/* BC2C04 80240174 45030001 */  bc1tl     .L8024017C
/* BC2C08 80240178 AE200074 */   sw       $zero, 0x74($s1)
.L8024017C:
/* BC2C0C 8024017C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BC2C10 80240180 8FB10014 */  lw        $s1, 0x14($sp)
/* BC2C14 80240184 8FB00010 */  lw        $s0, 0x10($sp)
/* BC2C18 80240188 24020002 */  addiu     $v0, $zero, 2
/* BC2C1C 8024018C 03E00008 */  jr        $ra
/* BC2C20 80240190 27BD0020 */   addiu    $sp, $sp, 0x20
