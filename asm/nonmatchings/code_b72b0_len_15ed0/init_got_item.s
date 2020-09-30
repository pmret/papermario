.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel init_got_item
/* C8200 80131B00 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C8204 80131B04 AFB00028 */  sw        $s0, 0x28($sp)
/* C8208 80131B08 0080802D */  daddu     $s0, $a0, $zero
/* C820C 80131B0C AFB30034 */  sw        $s3, 0x34($sp)
/* C8210 80131B10 00A0982D */  daddu     $s3, $a1, $zero
/* C8214 80131B14 AFB40038 */  sw        $s4, 0x38($sp)
/* C8218 80131B18 00C0A02D */  daddu     $s4, $a2, $zero
/* C821C 80131B1C AFB20030 */  sw        $s2, 0x30($sp)
/* C8220 80131B20 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* C8224 80131B24 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* C8228 80131B28 3C048015 */  lui       $a0, 0x8015
/* C822C 80131B2C 8C8465A0 */  lw        $a0, 0x65a0($a0)
/* C8230 80131B30 0000182D */  daddu     $v1, $zero, $zero
/* C8234 80131B34 AFBF0040 */  sw        $ra, 0x40($sp)
/* C8238 80131B38 AFB5003C */  sw        $s5, 0x3c($sp)
/* C823C 80131B3C AFB1002C */  sw        $s1, 0x2c($sp)
.L80131B40:
/* C8240 80131B40 8C820000 */  lw        $v0, ($a0)
/* C8244 80131B44 10400006 */  beqz      $v0, .L80131B60
/* C8248 80131B48 28620100 */   slti     $v0, $v1, 0x100
/* C824C 80131B4C 24630001 */  addiu     $v1, $v1, 1
/* C8250 80131B50 28620100 */  slti      $v0, $v1, 0x100
/* C8254 80131B54 1440FFFA */  bnez      $v0, .L80131B40
/* C8258 80131B58 24840004 */   addiu    $a0, $a0, 4
/* C825C 80131B5C 28620100 */  slti      $v0, $v1, 0x100
.L80131B60:
/* C8260 80131B60 54400003 */  bnel      $v0, $zero, .L80131B70
/* C8264 80131B64 2404005C */   addiu    $a0, $zero, 0x5c
.L80131B68:
/* C8268 80131B68 0804C6DA */  j         .L80131B68
/* C826C 80131B6C 00000000 */   nop      
.L80131B70:
/* C8270 80131B70 0C00AB39 */  jal       heap_malloc
/* C8274 80131B74 0060A82D */   daddu    $s5, $v1, $zero
/* C8278 80131B78 00152080 */  sll       $a0, $s5, 2
/* C827C 80131B7C 3C038015 */  lui       $v1, 0x8015
/* C8280 80131B80 8C6365A0 */  lw        $v1, 0x65a0($v1)
/* C8284 80131B84 3C058015 */  lui       $a1, 0x8015
/* C8288 80131B88 24A512F8 */  addiu     $a1, $a1, 0x12f8
/* C828C 80131B8C 00832021 */  addu      $a0, $a0, $v1
/* C8290 80131B90 8CA30000 */  lw        $v1, ($a1)
/* C8294 80131B94 0040882D */  daddu     $s1, $v0, $zero
/* C8298 80131B98 AC910000 */  sw        $s1, ($a0)
/* C829C 80131B9C 24630001 */  addiu     $v1, $v1, 1
/* C82A0 80131BA0 16200003 */  bnez      $s1, .L80131BB0
/* C82A4 80131BA4 ACA30000 */   sw       $v1, ($a1)
.L80131BA8:
/* C82A8 80131BA8 0804C6EA */  j         .L80131BA8
/* C82AC 80131BAC 00000000 */   nop      
.L80131BB0:
/* C82B0 80131BB0 3210FFFF */  andi      $s0, $s0, 0xffff
/* C82B4 80131BB4 3C030200 */  lui       $v1, 0x200
/* C82B8 80131BB8 34630017 */  ori       $v1, $v1, 0x17
/* C82BC 80131BBC 2402FFFF */  addiu     $v0, $zero, -1
/* C82C0 80131BC0 A222001D */  sb        $v0, 0x1d($s1)
/* C82C4 80131BC4 12600004 */  beqz      $s3, .L80131BD8
/* C82C8 80131BC8 AE230000 */   sw       $v1, ($s1)
/* C82CC 80131BCC 3C020600 */  lui       $v0, 0x600
/* C82D0 80131BD0 34420017 */  ori       $v0, $v0, 0x17
/* C82D4 80131BD4 AE220000 */  sw        $v0, ($s1)
.L80131BD8:
/* C82D8 80131BD8 2402001C */  addiu     $v0, $zero, 0x1c
/* C82DC 80131BDC A6340006 */  sh        $s4, 6($s1)
/* C82E0 80131BE0 A222001B */  sb        $v0, 0x1b($s1)
/* C82E4 80131BE4 A220001A */  sb        $zero, 0x1a($s1)
/* C82E8 80131BE8 A6200004 */  sh        $zero, 4($s1)
/* C82EC 80131BEC C6400028 */  lwc1      $f0, 0x28($s2)
/* C82F0 80131BF0 8E230000 */  lw        $v1, ($s1)
/* C82F4 80131BF4 E6200008 */  swc1      $f0, 8($s1)
/* C82F8 80131BF8 C640002C */  lwc1      $f0, 0x2c($s2)
/* C82FC 80131BFC 2402FFFF */  addiu     $v0, $zero, -1
/* C8300 80131C00 E620000C */  swc1      $f0, 0xc($s1)
/* C8304 80131C04 C6420030 */  lwc1      $f2, 0x30($s2)
/* C8308 80131C08 3C013F80 */  lui       $at, 0x3f80
/* C830C 80131C0C 44810000 */  mtc1      $at, $f0
/* C8310 80131C10 34634000 */  ori       $v1, $v1, 0x4000
/* C8314 80131C14 A6220020 */  sh        $v0, 0x20($s1)
/* C8318 80131C18 24020001 */  addiu     $v0, $zero, 1
/* C831C 80131C1C A222002E */  sb        $v0, 0x2e($s1)
/* C8320 80131C20 2402D8F1 */  addiu     $v0, $zero, -0x270f
/* C8324 80131C24 A6220034 */  sh        $v0, 0x34($s1)
/* C8328 80131C28 A6220036 */  sh        $v0, 0x36($s1)
/* C832C 80131C2C A6220038 */  sh        $v0, 0x38($s1)
/* C8330 80131C30 00101140 */  sll       $v0, $s0, 5
/* C8334 80131C34 A6300018 */  sh        $s0, 0x18($s1)
/* C8338 80131C38 AE200014 */  sw        $zero, 0x14($s1)
/* C833C 80131C3C A220001C */  sb        $zero, 0x1c($s1)
/* C8340 80131C40 A620001E */  sh        $zero, 0x1e($s1)
/* C8344 80131C44 AE230000 */  sw        $v1, ($s1)
/* C8348 80131C48 E6200030 */  swc1      $f0, 0x30($s1)
/* C834C 80131C4C E6220010 */  swc1      $f2, 0x10($s1)
/* C8350 80131C50 3C018008 */  lui       $at, 0x8008
/* C8354 80131C54 00220821 */  addu      $at, $at, $v0
/* C8358 80131C58 942278F8 */  lhu       $v0, 0x78f8($at)
/* C835C 80131C5C 30421000 */  andi      $v0, $v0, 0x1000
/* C8360 80131C60 10400005 */  beqz      $v0, .L80131C78
/* C8364 80131C64 3C020004 */   lui      $v0, 4
/* C8368 80131C68 00621025 */  or        $v0, $v1, $v0
/* C836C 80131C6C 2403BFFF */  addiu     $v1, $zero, -0x4001
/* C8370 80131C70 00431024 */  and       $v0, $v0, $v1
/* C8374 80131C74 AE220000 */  sw        $v0, ($s1)
.L80131C78:
/* C8378 80131C78 3C088015 */  lui       $t0, 0x8015
/* C837C 80131C7C 25085D84 */  addiu     $t0, $t0, 0x5d84
/* C8380 80131C80 8D020000 */  lw        $v0, ($t0)
/* C8384 80131C84 10400004 */  beqz      $v0, .L80131C98
/* C8388 80131C88 3C030002 */   lui      $v1, 2
/* C838C 80131C8C 8E220000 */  lw        $v0, ($s1)
/* C8390 80131C90 00431025 */  or        $v0, $v0, $v1
/* C8394 80131C94 AE220000 */  sw        $v0, ($s1)
.L80131C98:
/* C8398 80131C98 0000202D */  daddu     $a0, $zero, $zero
/* C839C 80131C9C 24020001 */  addiu     $v0, $zero, 1
/* C83A0 80131CA0 8E250008 */  lw        $a1, 8($s1)
/* C83A4 80131CA4 8E26000C */  lw        $a2, 0xc($s1)
/* C83A8 80131CA8 8D030000 */  lw        $v1, ($t0)
/* C83AC 80131CAC 8E270010 */  lw        $a3, 0x10($s1)
/* C83B0 80131CB0 00431023 */  subu      $v0, $v0, $v1
/* C83B4 80131CB4 0C044898 */  jal       create_shadow_type
/* C83B8 80131CB8 AD020000 */   sw       $v0, ($t0)
/* C83BC 80131CBC 00022400 */  sll       $a0, $v0, 0x10
/* C83C0 80131CC0 00042403 */  sra       $a0, $a0, 0x10
/* C83C4 80131CC4 0C044181 */  jal       get_shadow_by_index
/* C83C8 80131CC8 A6220020 */   sh       $v0, 0x20($s1)
/* C83CC 80131CCC 3C040002 */  lui       $a0, 2
/* C83D0 80131CD0 27A50018 */  addiu     $a1, $sp, 0x18
/* C83D4 80131CD4 27A6001C */  addiu     $a2, $sp, 0x1c
/* C83D8 80131CD8 27A70020 */  addiu     $a3, $sp, 0x20
/* C83DC 80131CDC 0040802D */  daddu     $s0, $v0, $zero
/* C83E0 80131CE0 8E020000 */  lw        $v0, ($s0)
/* C83E4 80131CE4 3C01447A */  lui       $at, 0x447a
/* C83E8 80131CE8 44810000 */  mtc1      $at, $f0
/* C83EC 80131CEC 3C014140 */  lui       $at, 0x4140
/* C83F0 80131CF0 44811000 */  mtc1      $at, $f2
/* C83F4 80131CF4 34420001 */  ori       $v0, $v0, 1
/* C83F8 80131CF8 AE020000 */  sw        $v0, ($s0)
/* C83FC 80131CFC 27A20024 */  addiu     $v0, $sp, 0x24
/* C8400 80131D00 E7A00024 */  swc1      $f0, 0x24($sp)
/* C8404 80131D04 C6260008 */  lwc1      $f6, 8($s1)
/* C8408 80131D08 C620000C */  lwc1      $f0, 0xc($s1)
/* C840C 80131D0C C6240010 */  lwc1      $f4, 0x10($s1)
/* C8410 80131D10 46020000 */  add.s     $f0, $f0, $f2
/* C8414 80131D14 E7A60018 */  swc1      $f6, 0x18($sp)
/* C8418 80131D18 E7A40020 */  swc1      $f4, 0x20($sp)
/* C841C 80131D1C E7A0001C */  swc1      $f0, 0x1c($sp)
/* C8420 80131D20 0C0372DF */  jal       func_800DCB7C
/* C8424 80131D24 AFA20010 */   sw       $v0, 0x10($sp)
/* C8428 80131D28 C7A00018 */  lwc1      $f0, 0x18($sp)
/* C842C 80131D2C C7A2001C */  lwc1      $f2, 0x1c($sp)
/* C8430 80131D30 C7A40020 */  lwc1      $f4, 0x20($sp)
/* C8434 80131D34 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C8438 80131D38 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C843C 80131D3C E6000010 */  swc1      $f0, 0x10($s0)
/* C8440 80131D40 E6020014 */  swc1      $f2, 0x14($s0)
/* C8444 80131D44 E6040018 */  swc1      $f4, 0x18($s0)
/* C8448 80131D48 C7A20024 */  lwc1      $f2, 0x24($sp)
/* C844C 80131D4C 3C013F00 */  lui       $at, 0x3f00
/* C8450 80131D50 44810000 */  mtc1      $at, $f0
/* C8454 80131D54 C444011C */  lwc1      $f4, 0x11c($v0)
/* C8458 80131D58 46001082 */  mul.s     $f2, $f2, $f0
/* C845C 80131D5C 00000000 */  nop       
/* C8460 80131D60 AE00002C */  sw        $zero, 0x2c($s0)
/* C8464 80131D64 E6040028 */  swc1      $f4, 0x28($s0)
/* C8468 80131D68 C4400124 */  lwc1      $f0, 0x124($v0)
/* C846C 80131D6C 44051000 */  mfc1      $a1, $f2
/* C8470 80131D70 0200202D */  daddu     $a0, $s0, $zero
/* C8474 80131D74 0C044A17 */  jal       set_standard_shadow_scale
/* C8478 80131D78 E4800030 */   swc1     $f0, 0x30($a0)
/* C847C 80131D7C 0C04C44A */  jal       func_80131128
/* C8480 80131D80 0220202D */   daddu    $a0, $s1, $zero
/* C8484 80131D84 86230018 */  lh        $v1, 0x18($s1)
/* C8488 80131D88 24020157 */  addiu     $v0, $zero, 0x157
/* C848C 80131D8C 14620008 */  bne       $v1, $v0, .L80131DB0
/* C8490 80131D90 02A0102D */   daddu    $v0, $s5, $zero
/* C8494 80131D94 3C058010 */  lui       $a1, 0x8010
/* C8498 80131D98 24A54AC0 */  addiu     $a1, $a1, 0x4ac0
/* C849C 80131D9C 0C04C27C */  jal       func_801309F0
/* C84A0 80131DA0 0220202D */   daddu    $a0, $s1, $zero
/* C84A4 80131DA4 0C04C2B3 */  jal       func_80130ACC
/* C84A8 80131DA8 0220202D */   daddu    $a0, $s1, $zero
/* C84AC 80131DAC 02A0102D */  daddu     $v0, $s5, $zero
.L80131DB0:
/* C84B0 80131DB0 8FBF0040 */  lw        $ra, 0x40($sp)
/* C84B4 80131DB4 8FB5003C */  lw        $s5, 0x3c($sp)
/* C84B8 80131DB8 8FB40038 */  lw        $s4, 0x38($sp)
/* C84BC 80131DBC 8FB30034 */  lw        $s3, 0x34($sp)
/* C84C0 80131DC0 8FB20030 */  lw        $s2, 0x30($sp)
/* C84C4 80131DC4 8FB1002C */  lw        $s1, 0x2c($sp)
/* C84C8 80131DC8 8FB00028 */  lw        $s0, 0x28($sp)
/* C84CC 80131DCC 03E00008 */  jr        $ra
/* C84D0 80131DD0 27BD0048 */   addiu    $sp, $sp, 0x48
