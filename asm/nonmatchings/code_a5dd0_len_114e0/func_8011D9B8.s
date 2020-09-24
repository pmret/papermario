.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011D9B8
/* B40B8 8011D9B8 27BDFB88 */  addiu     $sp, $sp, -0x478
/* B40BC 8011D9BC 3C048015 */  lui       $a0, 0x8015
/* B40C0 8011D9C0 248433B0 */  addiu     $a0, $a0, 0x33b0
/* B40C4 8011D9C4 AFBF0470 */  sw        $ra, 0x470($sp)
/* B40C8 8011D9C8 AFB7046C */  sw        $s7, 0x46c($sp)
/* B40CC 8011D9CC AFB60468 */  sw        $s6, 0x468($sp)
/* B40D0 8011D9D0 AFB50464 */  sw        $s5, 0x464($sp)
/* B40D4 8011D9D4 AFB40460 */  sw        $s4, 0x460($sp)
/* B40D8 8011D9D8 AFB3045C */  sw        $s3, 0x45c($sp)
/* B40DC 8011D9DC AFB20458 */  sw        $s2, 0x458($sp)
/* B40E0 8011D9E0 AFB10454 */  sw        $s1, 0x454($sp)
/* B40E4 8011D9E4 AFB00450 */  sw        $s0, 0x450($sp)
/* B40E8 8011D9E8 8C820000 */  lw        $v0, ($a0)
/* B40EC 8011D9EC 10400118 */  beqz      $v0, .L8011DE50
/* B40F0 8011D9F0 0000982D */   daddu    $s3, $zero, $zero
/* B40F4 8011D9F4 18400009 */  blez      $v0, .L8011DA1C
/* B40F8 8011D9F8 0260A82D */   daddu    $s5, $s3, $zero
/* B40FC 8011D9FC 27A30010 */  addiu     $v1, $sp, 0x10
.L8011DA00:
/* B4100 8011DA00 AC730000 */  sw        $s3, ($v1)
/* B4104 8011DA04 24630004 */  addiu     $v1, $v1, 4
/* B4108 8011DA08 8C820000 */  lw        $v0, ($a0)
/* B410C 8011DA0C 26730001 */  addiu     $s3, $s3, 1
/* B4110 8011DA10 0262102A */  slt       $v0, $s3, $v0
/* B4114 8011DA14 1440FFFA */  bnez      $v0, .L8011DA00
/* B4118 8011DA18 26B50001 */   addiu    $s5, $s5, 1
.L8011DA1C:
/* B411C 8011DA1C 3C028015 */  lui       $v0, 0x8015
/* B4120 8011DA20 8C4233AC */  lw        $v0, 0x33ac($v0)
/* B4124 8011DA24 00021080 */  sll       $v0, $v0, 2
/* B4128 8011DA28 3C148015 */  lui       $s4, 0x8015
/* B412C 8011DA2C 0282A021 */  addu      $s4, $s4, $v0
/* B4130 8011DA30 8E9433A0 */  lw        $s4, 0x33a0($s4)
/* B4134 8011DA34 26A2FFFF */  addiu     $v0, $s5, -1
/* B4138 8011DA38 1840001F */  blez      $v0, .L8011DAB8
/* B413C 8011DA3C 0000982D */   daddu    $s3, $zero, $zero
/* B4140 8011DA40 0040602D */  daddu     $t4, $v0, $zero
/* B4144 8011DA44 27AB0010 */  addiu     $t3, $sp, 0x10
/* B4148 8011DA48 0160502D */  daddu     $t2, $t3, $zero
.L8011DA4C:
/* B414C 8011DA4C 26650001 */  addiu     $a1, $s3, 1
/* B4150 8011DA50 00B5102A */  slt       $v0, $a1, $s5
/* B4154 8011DA54 50400015 */  beql      $v0, $zero, .L8011DAAC
/* B4158 8011DA58 26730001 */   addiu    $s3, $s3, 1
/* B415C 8011DA5C 0140482D */  daddu     $t1, $t2, $zero
/* B4160 8011DA60 00051080 */  sll       $v0, $a1, 2
/* B4164 8011DA64 004B3821 */  addu      $a3, $v0, $t3
.L8011DA68:
/* B4168 8011DA68 8D280000 */  lw        $t0, ($t1)
/* B416C 8011DA6C 8CE60000 */  lw        $a2, ($a3)
/* B4170 8011DA70 00081100 */  sll       $v0, $t0, 4
/* B4174 8011DA74 02828021 */  addu      $s0, $s4, $v0
/* B4178 8011DA78 00061100 */  sll       $v0, $a2, 4
/* B417C 8011DA7C 02822021 */  addu      $a0, $s4, $v0
/* B4180 8011DA80 8E030004 */  lw        $v1, 4($s0)
/* B4184 8011DA84 8C820004 */  lw        $v0, 4($a0)
/* B4188 8011DA88 0043102A */  slt       $v0, $v0, $v1
/* B418C 8011DA8C 10400003 */  beqz      $v0, .L8011DA9C
/* B4190 8011DA90 24A50001 */   addiu    $a1, $a1, 1
/* B4194 8011DA94 AD260000 */  sw        $a2, ($t1)
/* B4198 8011DA98 ACE80000 */  sw        $t0, ($a3)
.L8011DA9C:
/* B419C 8011DA9C 00B5102A */  slt       $v0, $a1, $s5
/* B41A0 8011DAA0 1440FFF1 */  bnez      $v0, .L8011DA68
/* B41A4 8011DAA4 24E70004 */   addiu    $a3, $a3, 4
/* B41A8 8011DAA8 26730001 */  addiu     $s3, $s3, 1
.L8011DAAC:
/* B41AC 8011DAAC 026C102A */  slt       $v0, $s3, $t4
/* B41B0 8011DAB0 1440FFE6 */  bnez      $v0, .L8011DA4C
/* B41B4 8011DAB4 254A0004 */   addiu    $t2, $t2, 4
.L8011DAB8:
/* B41B8 8011DAB8 3C028015 */  lui       $v0, 0x8015
/* B41BC 8011DABC 8C4233AC */  lw        $v0, 0x33ac($v0)
/* B41C0 8011DAC0 00021080 */  sll       $v0, $v0, 2
/* B41C4 8011DAC4 3C148015 */  lui       $s4, 0x8015
/* B41C8 8011DAC8 0282A021 */  addu      $s4, $s4, $v0
/* B41CC 8011DACC 8E9433A0 */  lw        $s4, 0x33a0($s4)
/* B41D0 8011DAD0 26A2FFFF */  addiu     $v0, $s5, -1
/* B41D4 8011DAD4 18400027 */  blez      $v0, .L8011DB74
/* B41D8 8011DAD8 0000982D */   daddu    $s3, $zero, $zero
/* B41DC 8011DADC 3C0D002D */  lui       $t5, 0x2d
/* B41E0 8011DAE0 35ADC6BF */  ori       $t5, $t5, 0xc6bf
/* B41E4 8011DAE4 0040602D */  daddu     $t4, $v0, $zero
/* B41E8 8011DAE8 27AB0010 */  addiu     $t3, $sp, 0x10
/* B41EC 8011DAEC 0160502D */  daddu     $t2, $t3, $zero
.L8011DAF0:
/* B41F0 8011DAF0 8D420000 */  lw        $v0, ($t2)
/* B41F4 8011DAF4 00021100 */  sll       $v0, $v0, 4
/* B41F8 8011DAF8 02828021 */  addu      $s0, $s4, $v0
/* B41FC 8011DAFC 8E020004 */  lw        $v0, 4($s0)
/* B4200 8011DB00 01A2102A */  slt       $v0, $t5, $v0
/* B4204 8011DB04 50400018 */  beql      $v0, $zero, .L8011DB68
/* B4208 8011DB08 26730001 */   addiu    $s3, $s3, 1
/* B420C 8011DB0C 26650001 */  addiu     $a1, $s3, 1
/* B4210 8011DB10 00B5102A */  slt       $v0, $a1, $s5
/* B4214 8011DB14 10400013 */  beqz      $v0, .L8011DB64
/* B4218 8011DB18 00051080 */   sll      $v0, $a1, 2
/* B421C 8011DB1C 0140482D */  daddu     $t1, $t2, $zero
/* B4220 8011DB20 004B3821 */  addu      $a3, $v0, $t3
.L8011DB24:
/* B4224 8011DB24 8D280000 */  lw        $t0, ($t1)
/* B4228 8011DB28 8CE60000 */  lw        $a2, ($a3)
/* B422C 8011DB2C 00081100 */  sll       $v0, $t0, 4
/* B4230 8011DB30 02828021 */  addu      $s0, $s4, $v0
/* B4234 8011DB34 00061100 */  sll       $v0, $a2, 4
/* B4238 8011DB38 02822021 */  addu      $a0, $s4, $v0
/* B423C 8011DB3C 8E020004 */  lw        $v0, 4($s0)
/* B4240 8011DB40 8C830004 */  lw        $v1, 4($a0)
/* B4244 8011DB44 0043102A */  slt       $v0, $v0, $v1
/* B4248 8011DB48 10400003 */  beqz      $v0, .L8011DB58
/* B424C 8011DB4C 24A50001 */   addiu    $a1, $a1, 1
/* B4250 8011DB50 AD260000 */  sw        $a2, ($t1)
/* B4254 8011DB54 ACE80000 */  sw        $t0, ($a3)
.L8011DB58:
/* B4258 8011DB58 00B5102A */  slt       $v0, $a1, $s5
/* B425C 8011DB5C 1440FFF1 */  bnez      $v0, .L8011DB24
/* B4260 8011DB60 24E70004 */   addiu    $a3, $a3, 4
.L8011DB64:
/* B4264 8011DB64 26730001 */  addiu     $s3, $s3, 1
.L8011DB68:
/* B4268 8011DB68 026C102A */  slt       $v0, $s3, $t4
/* B426C 8011DB6C 1440FFE0 */  bnez      $v0, .L8011DAF0
/* B4270 8011DB70 254A0004 */   addiu    $t2, $t2, 4
.L8011DB74:
/* B4274 8011DB74 3C028015 */  lui       $v0, 0x8015
/* B4278 8011DB78 8C4233AC */  lw        $v0, 0x33ac($v0)
/* B427C 8011DB7C 00021080 */  sll       $v0, $v0, 2
/* B4280 8011DB80 3C148015 */  lui       $s4, 0x8015
/* B4284 8011DB84 0282A021 */  addu      $s4, $s4, $v0
/* B4288 8011DB88 8E9433A0 */  lw        $s4, 0x33a0($s4)
/* B428C 8011DB8C 26A2FFFF */  addiu     $v0, $s5, -1
/* B4290 8011DB90 1840002A */  blez      $v0, .L8011DC3C
/* B4294 8011DB94 0000982D */   daddu    $s3, $zero, $zero
/* B4298 8011DB98 3C0B000C */  lui       $t3, 0xc
/* B429C 8011DB9C 356B3500 */  ori       $t3, $t3, 0x3500
/* B42A0 8011DBA0 0040682D */  daddu     $t5, $v0, $zero
/* B42A4 8011DBA4 27AC0010 */  addiu     $t4, $sp, 0x10
/* B42A8 8011DBA8 0180502D */  daddu     $t2, $t4, $zero
.L8011DBAC:
/* B42AC 8011DBAC 8D420000 */  lw        $v0, ($t2)
/* B42B0 8011DBB0 00021100 */  sll       $v0, $v0, 4
/* B42B4 8011DBB4 02828021 */  addu      $s0, $s4, $v0
/* B42B8 8011DBB8 8E020004 */  lw        $v0, 4($s0)
/* B42BC 8011DBBC 0162102A */  slt       $v0, $t3, $v0
/* B42C0 8011DBC0 1440001E */  bnez      $v0, .L8011DC3C
/* B42C4 8011DBC4 00000000 */   nop      
/* B42C8 8011DBC8 26650001 */  addiu     $a1, $s3, 1
/* B42CC 8011DBCC 00B5102A */  slt       $v0, $a1, $s5
/* B42D0 8011DBD0 10400016 */  beqz      $v0, .L8011DC2C
/* B42D4 8011DBD4 00051080 */   sll      $v0, $a1, 2
/* B42D8 8011DBD8 0140482D */  daddu     $t1, $t2, $zero
/* B42DC 8011DBDC 004C3821 */  addu      $a3, $v0, $t4
.L8011DBE0:
/* B42E0 8011DBE0 8CE80000 */  lw        $t0, ($a3)
/* B42E4 8011DBE4 8D260000 */  lw        $a2, ($t1)
/* B42E8 8011DBE8 00081100 */  sll       $v0, $t0, 4
/* B42EC 8011DBEC 02822021 */  addu      $a0, $s4, $v0
/* B42F0 8011DBF0 00061100 */  sll       $v0, $a2, 4
/* B42F4 8011DBF4 8C830004 */  lw        $v1, 4($a0)
/* B42F8 8011DBF8 02828021 */  addu      $s0, $s4, $v0
/* B42FC 8011DBFC 0163102A */  slt       $v0, $t3, $v1
/* B4300 8011DC00 5440000B */  bnel      $v0, $zero, .L8011DC30
/* B4304 8011DC04 26730001 */   addiu    $s3, $s3, 1
/* B4308 8011DC08 8E020004 */  lw        $v0, 4($s0)
/* B430C 8011DC0C 0043102A */  slt       $v0, $v0, $v1
/* B4310 8011DC10 10400003 */  beqz      $v0, .L8011DC20
/* B4314 8011DC14 24A50001 */   addiu    $a1, $a1, 1
/* B4318 8011DC18 AD280000 */  sw        $t0, ($t1)
/* B431C 8011DC1C ACE60000 */  sw        $a2, ($a3)
.L8011DC20:
/* B4320 8011DC20 00B5102A */  slt       $v0, $a1, $s5
/* B4324 8011DC24 1440FFEE */  bnez      $v0, .L8011DBE0
/* B4328 8011DC28 24E70004 */   addiu    $a3, $a3, 4
.L8011DC2C:
/* B432C 8011DC2C 26730001 */  addiu     $s3, $s3, 1
.L8011DC30:
/* B4330 8011DC30 026D102A */  slt       $v0, $s3, $t5
/* B4334 8011DC34 1440FFDD */  bnez      $v0, .L8011DBAC
/* B4338 8011DC38 254A0004 */   addiu    $t2, $t2, 4
.L8011DC3C:
/* B433C 8011DC3C 3C038015 */  lui       $v1, 0x8015
/* B4340 8011DC40 8C6333AC */  lw        $v1, 0x33ac($v1)
/* B4344 8011DC44 3C02800A */  lui       $v0, 0x800a
/* B4348 8011DC48 8C42A650 */  lw        $v0, -0x59b0($v0)
/* B434C 8011DC4C 3C018015 */  lui       $at, 0x8015
/* B4350 8011DC50 AC35B7F0 */  sw        $s5, -0x4810($at)
/* B4354 8011DC54 00031880 */  sll       $v1, $v1, 2
/* B4358 8011DC58 30420080 */  andi      $v0, $v0, 0x80
/* B435C 8011DC5C 3C148015 */  lui       $s4, 0x8015
/* B4360 8011DC60 0283A021 */  addu      $s4, $s4, $v1
/* B4364 8011DC64 8E9433A0 */  lw        $s4, 0x33a0($s4)
/* B4368 8011DC68 10400061 */  beqz      $v0, .L8011DDF0
/* B436C 8011DC6C 0000B02D */   daddu    $s6, $zero, $zero
/* B4370 8011DC70 27B00410 */  addiu     $s0, $sp, 0x410
/* B4374 8011DC74 0200202D */  daddu     $a0, $s0, $zero
/* B4378 8011DC78 3C120001 */  lui       $s2, 1
/* B437C 8011DC7C 3C013F80 */  lui       $at, 0x3f80
/* B4380 8011DC80 44810000 */  mtc1      $at, $f0
/* B4384 8011DC84 36521630 */  ori       $s2, $s2, 0x1630
/* B4388 8011DC88 44050000 */  mfc1      $a1, $f0
/* B438C 8011DC8C 3C06BF80 */  lui       $a2, 0xbf80
/* B4390 8011DC90 0C019DF0 */  jal       guScaleF
/* B4394 8011DC94 00A0382D */   daddu    $a3, $a1, $zero
/* B4398 8011DC98 0200202D */  daddu     $a0, $s0, $zero
/* B439C 8011DC9C 3C108007 */  lui       $s0, 0x8007
/* B43A0 8011DCA0 261041F0 */  addiu     $s0, $s0, 0x41f0
/* B43A4 8011DCA4 3C11800A */  lui       $s1, 0x800a
/* B43A8 8011DCA8 2631A674 */  addiu     $s1, $s1, -0x598c
/* B43AC 8011DCAC 96050000 */  lhu       $a1, ($s0)
/* B43B0 8011DCB0 8E220000 */  lw        $v0, ($s1)
/* B43B4 8011DCB4 00052980 */  sll       $a1, $a1, 6
/* B43B8 8011DCB8 00B22821 */  addu      $a1, $a1, $s2
/* B43BC 8011DCBC 0C019D40 */  jal       guMtxF2L
/* B43C0 8011DCC0 00452821 */   addu     $a1, $v0, $a1
/* B43C4 8011DCC4 96020000 */  lhu       $v0, ($s0)
/* B43C8 8011DCC8 02C0982D */  daddu     $s3, $s6, $zero
/* B43CC 8011DCCC 24430001 */  addiu     $v1, $v0, 1
/* B43D0 8011DCD0 3042FFFF */  andi      $v0, $v0, 0xffff
/* B43D4 8011DCD4 00021180 */  sll       $v0, $v0, 6
/* B43D8 8011DCD8 A6030000 */  sh        $v1, ($s0)
/* B43DC 8011DCDC 8E230000 */  lw        $v1, ($s1)
/* B43E0 8011DCE0 00521021 */  addu      $v0, $v0, $s2
/* B43E4 8011DCE4 1AA00050 */  blez      $s5, .L8011DE28
/* B43E8 8011DCE8 0062B821 */   addu     $s7, $v1, $v0
/* B43EC 8011DCEC 3C11800A */  lui       $s1, 0x800a
/* B43F0 8011DCF0 2631A66C */  addiu     $s1, $s1, -0x5994
/* B43F4 8011DCF4 3C12DE00 */  lui       $s2, 0xde00
/* B43F8 8011DCF8 00131080 */  sll       $v0, $s3, 2
.L8011DCFC:
/* B43FC 8011DCFC 03A21021 */  addu      $v0, $sp, $v0
/* B4400 8011DD00 8C420010 */  lw        $v0, 0x10($v0)
/* B4404 8011DD04 00021100 */  sll       $v0, $v0, 4
/* B4408 8011DD08 02828021 */  addu      $s0, $s4, $v0
/* B440C 8011DD0C 8E020000 */  lw        $v0, ($s0)
/* B4410 8011DD10 8E03000C */  lw        $v1, 0xc($s0)
/* B4414 8011DD14 30420002 */  andi      $v0, $v0, 2
/* B4418 8011DD18 10400004 */  beqz      $v0, .L8011DD2C
/* B441C 8011DD1C 00000000 */   nop      
/* B4420 8011DD20 8E360000 */  lw        $s6, ($s1)
/* B4424 8011DD24 26C20008 */  addiu     $v0, $s6, 8
/* B4428 8011DD28 AE220000 */  sw        $v0, ($s1)
.L8011DD2C:
/* B442C 8011DD2C 0060F809 */  jalr      $v1
/* B4430 8011DD30 8E040008 */   lw       $a0, 8($s0)
/* B4434 8011DD34 8E020000 */  lw        $v0, ($s0)
/* B4438 8011DD38 30420002 */  andi      $v0, $v0, 2
/* B443C 8011DD3C 10400027 */  beqz      $v0, .L8011DDDC
/* B4440 8011DD40 26730001 */   addiu    $s3, $s3, 1
/* B4444 8011DD44 3C05DA38 */  lui       $a1, 0xda38
/* B4448 8011DD48 34A50005 */  ori       $a1, $a1, 5
/* B444C 8011DD4C 3C06DA38 */  lui       $a2, 0xda38
/* B4450 8011DD50 8E230000 */  lw        $v1, ($s1)
/* B4454 8011DD54 3C02DF00 */  lui       $v0, 0xdf00
/* B4458 8011DD58 0060202D */  daddu     $a0, $v1, $zero
/* B445C 8011DD5C 24630008 */  addiu     $v1, $v1, 8
/* B4460 8011DD60 AE230000 */  sw        $v1, ($s1)
/* B4464 8011DD64 AC820000 */  sw        $v0, ($a0)
/* B4468 8011DD68 3C02DE01 */  lui       $v0, 0xde01
/* B446C 8011DD6C AC800004 */  sw        $zero, 4($a0)
/* B4470 8011DD70 AEC20000 */  sw        $v0, ($s6)
/* B4474 8011DD74 24620008 */  addiu     $v0, $v1, 8
/* B4478 8011DD78 26C40008 */  addiu     $a0, $s6, 8
/* B447C 8011DD7C AEC30004 */  sw        $v1, 4($s6)
/* B4480 8011DD80 AE220000 */  sw        $v0, ($s1)
/* B4484 8011DD84 24620010 */  addiu     $v0, $v1, 0x10
/* B4488 8011DD88 AC720000 */  sw        $s2, ($v1)
/* B448C 8011DD8C AC640004 */  sw        $a0, 4($v1)
/* B4490 8011DD90 AE220000 */  sw        $v0, ($s1)
/* B4494 8011DD94 24620018 */  addiu     $v0, $v1, 0x18
/* B4498 8011DD98 AC650008 */  sw        $a1, 8($v1)
/* B449C 8011DD9C AC77000C */  sw        $s7, 0xc($v1)
/* B44A0 8011DDA0 AE220000 */  sw        $v0, ($s1)
/* B44A4 8011DDA4 AC640014 */  sw        $a0, 0x14($v1)
/* B44A8 8011DDA8 3C04800A */  lui       $a0, 0x800a
/* B44AC 8011DDAC 8484A634 */  lh        $a0, -0x59cc($a0)
/* B44B0 8011DDB0 24620020 */  addiu     $v0, $v1, 0x20
/* B44B4 8011DDB4 AC720010 */  sw        $s2, 0x10($v1)
/* B44B8 8011DDB8 AE220000 */  sw        $v0, ($s1)
/* B44BC 8011DDBC 3C02800A */  lui       $v0, 0x800a
/* B44C0 8011DDC0 8C42A674 */  lw        $v0, -0x598c($v0)
/* B44C4 8011DDC4 34C60007 */  ori       $a2, $a2, 7
/* B44C8 8011DDC8 AC660018 */  sw        $a2, 0x18($v1)
/* B44CC 8011DDCC 00042180 */  sll       $a0, $a0, 6
/* B44D0 8011DDD0 24840030 */  addiu     $a0, $a0, 0x30
/* B44D4 8011DDD4 00441021 */  addu      $v0, $v0, $a0
/* B44D8 8011DDD8 AC62001C */  sw        $v0, 0x1c($v1)
.L8011DDDC:
/* B44DC 8011DDDC 0275102A */  slt       $v0, $s3, $s5
/* B44E0 8011DDE0 1440FFC6 */  bnez      $v0, .L8011DCFC
/* B44E4 8011DDE4 00131080 */   sll      $v0, $s3, 2
/* B44E8 8011DDE8 0804778A */  j         .L8011DE28
/* B44EC 8011DDEC 00000000 */   nop      
.L8011DDF0:
/* B44F0 8011DDF0 1AA0000D */  blez      $s5, .L8011DE28
/* B44F4 8011DDF4 0000982D */   daddu    $s3, $zero, $zero
/* B44F8 8011DDF8 27B10010 */  addiu     $s1, $sp, 0x10
.L8011DDFC:
/* B44FC 8011DDFC 8E220000 */  lw        $v0, ($s1)
/* B4500 8011DE00 26310004 */  addiu     $s1, $s1, 4
/* B4504 8011DE04 00021100 */  sll       $v0, $v0, 4
/* B4508 8011DE08 02828021 */  addu      $s0, $s4, $v0
/* B450C 8011DE0C 8E03000C */  lw        $v1, 0xc($s0)
/* B4510 8011DE10 8E040008 */  lw        $a0, 8($s0)
/* B4514 8011DE14 0060F809 */  jalr      $v1
/* B4518 8011DE18 26730001 */   addiu    $s3, $s3, 1
/* B451C 8011DE1C 0275102A */  slt       $v0, $s3, $s5
/* B4520 8011DE20 1440FFF6 */  bnez      $v0, .L8011DDFC
/* B4524 8011DE24 00000000 */   nop      
.L8011DE28:
/* B4528 8011DE28 3C038015 */  lui       $v1, 0x8015
/* B452C 8011DE2C 246333AC */  addiu     $v1, $v1, 0x33ac
/* B4530 8011DE30 8C620000 */  lw        $v0, ($v1)
/* B4534 8011DE34 24420001 */  addiu     $v0, $v0, 1
/* B4538 8011DE38 AC620000 */  sw        $v0, ($v1)
/* B453C 8011DE3C 28420003 */  slti      $v0, $v0, 3
/* B4540 8011DE40 50400001 */  beql      $v0, $zero, .L8011DE48
/* B4544 8011DE44 AC600000 */   sw       $zero, ($v1)
.L8011DE48:
/* B4548 8011DE48 3C018015 */  lui       $at, 0x8015
/* B454C 8011DE4C AC2033B0 */  sw        $zero, 0x33b0($at)
.L8011DE50:
/* B4550 8011DE50 8FBF0470 */  lw        $ra, 0x470($sp)
/* B4554 8011DE54 8FB7046C */  lw        $s7, 0x46c($sp)
/* B4558 8011DE58 8FB60468 */  lw        $s6, 0x468($sp)
/* B455C 8011DE5C 8FB50464 */  lw        $s5, 0x464($sp)
/* B4560 8011DE60 8FB40460 */  lw        $s4, 0x460($sp)
/* B4564 8011DE64 8FB3045C */  lw        $s3, 0x45c($sp)
/* B4568 8011DE68 8FB20458 */  lw        $s2, 0x458($sp)
/* B456C 8011DE6C 8FB10454 */  lw        $s1, 0x454($sp)
/* B4570 8011DE70 8FB00450 */  lw        $s0, 0x450($sp)
/* B4574 8011DE74 03E00008 */  jr        $ra
/* B4578 8011DE78 27BD0478 */   addiu    $sp, $sp, 0x478
/* B457C 8011DE7C 00000000 */  nop       
