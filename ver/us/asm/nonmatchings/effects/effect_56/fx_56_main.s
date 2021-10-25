.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_56_main
/* 3740B0 E0070000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3740B4 E0070004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3740B8 E0070008 4485A000 */  mtc1      $a1, $f20
/* 3740BC E007000C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3740C0 E0070010 4486B000 */  mtc1      $a2, $f22
/* 3740C4 E0070014 AFB30034 */  sw        $s3, 0x34($sp)
/* 3740C8 E0070018 0080982D */  daddu     $s3, $a0, $zero
/* 3740CC E007001C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3740D0 E0070020 4487C000 */  mtc1      $a3, $f24
/* 3740D4 E0070024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3740D8 E0070028 AFB20030 */  sw        $s2, 0x30($sp)
/* 3740DC E007002C 8FB2006C */  lw        $s2, 0x6c($sp)
/* 3740E0 E0070030 3C02E007 */  lui       $v0, %hi(fx_56_init)
/* 3740E4 E0070034 244201EC */  addiu     $v0, $v0, %lo(fx_56_init)
/* 3740E8 E0070038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3740EC E007003C 3C02E007 */  lui       $v0, %hi(fx_56_update)
/* 3740F0 E0070040 244201F4 */  addiu     $v0, $v0, %lo(fx_56_update)
/* 3740F4 E0070044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3740F8 E0070048 3C02E007 */  lui       $v0, %hi(fx_56_render)
/* 3740FC E007004C 244206F0 */  addiu     $v0, $v0, %lo(fx_56_render)
/* 374100 E0070050 AFA20020 */  sw        $v0, 0x20($sp)
/* 374104 E0070054 24020038 */  addiu     $v0, $zero, 0x38
/* 374108 E0070058 AFBF0038 */  sw        $ra, 0x38($sp)
/* 37410C E007005C AFB1002C */  sw        $s1, 0x2c($sp)
/* 374110 E0070060 AFB00028 */  sw        $s0, 0x28($sp)
/* 374114 E0070064 AFA00010 */  sw        $zero, 0x10($sp)
/* 374118 E0070068 AFA00024 */  sw        $zero, 0x24($sp)
/* 37411C E007006C 0C080124 */  jal       shim_create_effect_instance
/* 374120 E0070070 AFA20014 */   sw       $v0, 0x14($sp)
/* 374124 E0070074 240419BC */  addiu     $a0, $zero, 0x19bc
/* 374128 E0070078 2411003D */  addiu     $s1, $zero, 0x3d
/* 37412C E007007C 0040802D */  daddu     $s0, $v0, $zero
/* 374130 E0070080 0C08012C */  jal       shim_general_heap_malloc
/* 374134 E0070084 AE110008 */   sw       $s1, 8($s0)
/* 374138 E0070088 0040182D */  daddu     $v1, $v0, $zero
/* 37413C E007008C 14600003 */  bnez      $v1, .LE007009C
/* 374140 E0070090 AE03000C */   sw       $v1, 0xc($s0)
.LE0070094:
/* 374144 E0070094 0801C025 */  j         .LE0070094
/* 374148 E0070098 00000000 */   nop
.LE007009C:
/* 37414C E007009C AC730000 */  sw        $s3, ($v1)
/* 374150 E00700A0 1E400004 */  bgtz      $s2, .LE00700B4
/* 374154 E00700A4 AC60003C */   sw       $zero, 0x3c($v1)
/* 374158 E00700A8 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 37415C E00700AC 0801C02E */  j         .LE00700B8
/* 374160 E00700B0 AC620038 */   sw       $v0, 0x38($v1)
.LE00700B4:
/* 374164 E00700B4 AC720038 */  sw        $s2, 0x38($v1)
.LE00700B8:
/* 374168 E00700B8 240400FF */  addiu     $a0, $zero, 0xff
/* 37416C E00700BC AC64004C */  sw        $a0, 0x4c($v1)
/* 374170 E00700C0 E4740004 */  swc1      $f20, 4($v1)
/* 374174 E00700C4 E4760008 */  swc1      $f22, 8($v1)
/* 374178 E00700C8 E478000C */  swc1      $f24, 0xc($v1)
/* 37417C E00700CC C7A00068 */  lwc1      $f0, 0x68($sp)
/* 374180 E00700D0 2402001E */  addiu     $v0, $zero, 0x1e
/* 374184 E00700D4 AC640040 */  sw        $a0, 0x40($v1)
/* 374188 E00700D8 AC640044 */  sw        $a0, 0x44($v1)
/* 37418C E00700DC AC640048 */  sw        $a0, 0x48($v1)
/* 374190 E00700E0 E4600060 */  swc1      $f0, 0x60($v1)
/* 374194 E00700E4 44820000 */  mtc1      $v0, $f0
/* 374198 E00700E8 00000000 */  nop
/* 37419C E00700EC 46800020 */  cvt.s.w   $f0, $f0
/* 3741A0 E00700F0 E4600010 */  swc1      $f0, 0x10($v1)
/* 3741A4 E00700F4 16600007 */  bnez      $s3, .LE0070114
/* 3741A8 E00700F8 E4600014 */   swc1     $f0, 0x14($v1)
/* 3741AC E00700FC 240200D7 */  addiu     $v0, $zero, 0xd7
/* 3741B0 E0070100 AC620050 */  sw        $v0, 0x50($v1)
/* 3741B4 E0070104 240200EB */  addiu     $v0, $zero, 0xeb
/* 3741B8 E0070108 AC640054 */  sw        $a0, 0x54($v1)
/* 3741BC E007010C 0801C049 */  j         .LE0070124
/* 3741C0 E0070110 AC620058 */   sw       $v0, 0x58($v1)
.LE0070114:
/* 3741C4 E0070114 2402007F */  addiu     $v0, $zero, 0x7f
/* 3741C8 E0070118 AC640050 */  sw        $a0, 0x50($v1)
/* 3741CC E007011C AC620054 */  sw        $v0, 0x54($v1)
/* 3741D0 E0070120 AC640058 */  sw        $a0, 0x58($v1)
.LE0070124:
/* 3741D4 E0070124 AC64005C */  sw        $a0, 0x5c($v1)
/* 3741D8 E0070128 2A420014 */  slti      $v0, $s2, 0x14
/* 3741DC E007012C 10400009 */  beqz      $v0, .LE0070154
/* 3741E0 E0070130 2463006C */   addiu    $v1, $v1, 0x6c
/* 3741E4 E0070134 2622FFFF */  addiu     $v0, $s1, -1
/* 3741E8 E0070138 3C0141A0 */  lui       $at, 0x41a0
/* 3741EC E007013C 44811000 */  mtc1      $at, $f2
/* 3741F0 E0070140 44820000 */  mtc1      $v0, $f0
/* 3741F4 E0070144 00000000 */  nop
/* 3741F8 E0070148 46800020 */  cvt.s.w   $f0, $f0
/* 3741FC E007014C 0801C05D */  j         .LE0070174
/* 374200 E0070150 46001083 */   div.s    $f2, $f2, $f0
.LE0070154:
/* 374204 E0070154 44920000 */  mtc1      $s2, $f0
/* 374208 E0070158 00000000 */  nop
/* 37420C E007015C 46800020 */  cvt.s.w   $f0, $f0
/* 374210 E0070160 2622FFFF */  addiu     $v0, $s1, -1
/* 374214 E0070164 44821000 */  mtc1      $v0, $f2
/* 374218 E0070168 00000000 */  nop
/* 37421C E007016C 468010A0 */  cvt.s.w   $f2, $f2
/* 374220 E0070170 46020083 */  div.s     $f2, $f0, $f2
.LE0070174:
/* 374224 E0070174 24040001 */  addiu     $a0, $zero, 1
/* 374228 E0070178 0091102A */  slt       $v0, $a0, $s1
/* 37422C E007017C 10400011 */  beqz      $v0, .LE00701C4
/* 374230 E0070180 0200102D */   daddu    $v0, $s0, $zero
.LE0070184:
/* 374234 E0070184 44840000 */  mtc1      $a0, $f0
/* 374238 E0070188 00000000 */  nop
/* 37423C E007018C 46800020 */  cvt.s.w   $f0, $f0
/* 374240 E0070190 46000007 */  neg.s     $f0, $f0
/* 374244 E0070194 46020002 */  mul.s     $f0, $f0, $f2
/* 374248 E0070198 00000000 */  nop
/* 37424C E007019C 24840001 */  addiu     $a0, $a0, 1
/* 374250 E00701A0 4600010D */  trunc.w.s $f4, $f0
/* 374254 E00701A4 44022000 */  mfc1      $v0, $f4
/* 374258 E00701A8 00000000 */  nop
/* 37425C E00701AC 2442FFFF */  addiu     $v0, $v0, -1
/* 374260 E00701B0 AC620030 */  sw        $v0, 0x30($v1)
/* 374264 E00701B4 0091102A */  slt       $v0, $a0, $s1
/* 374268 E00701B8 1440FFF2 */  bnez      $v0, .LE0070184
/* 37426C E00701BC 2463006C */   addiu    $v1, $v1, 0x6c
/* 374270 E00701C0 0200102D */  daddu     $v0, $s0, $zero
.LE00701C4:
/* 374274 E00701C4 8FBF0038 */  lw        $ra, 0x38($sp)
/* 374278 E00701C8 8FB30034 */  lw        $s3, 0x34($sp)
/* 37427C E00701CC 8FB20030 */  lw        $s2, 0x30($sp)
/* 374280 E00701D0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 374284 E00701D4 8FB00028 */  lw        $s0, 0x28($sp)
/* 374288 E00701D8 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 37428C E00701DC D7B60048 */  ldc1      $f22, 0x48($sp)
/* 374290 E00701E0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 374294 E00701E4 03E00008 */  jr        $ra
/* 374298 E00701E8 27BD0058 */   addiu    $sp, $sp, 0x58
