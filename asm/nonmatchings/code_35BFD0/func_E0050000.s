.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0050000
/* 35BFD0 E0050000 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 35BFD4 E0050004 F7B80090 */  sdc1      $f24, 0x90($sp)
/* 35BFD8 E0050008 4485C000 */  mtc1      $a1, $f24
/* 35BFDC E005000C F7BA0098 */  sdc1      $f26, 0x98($sp)
/* 35BFE0 E0050010 4486D000 */  mtc1      $a2, $f26
/* 35BFE4 E0050014 AFB20078 */  sw        $s2, 0x78($sp)
/* 35BFE8 E0050018 0080902D */  daddu     $s2, $a0, $zero
/* 35BFEC E005001C F7BC00A0 */  sdc1      $f28, 0xa0($sp)
/* 35BFF0 E0050020 4487E000 */  mtc1      $a3, $f28
/* 35BFF4 E0050024 27A40018 */  addiu     $a0, $sp, 0x18
/* 35BFF8 E0050028 F7B60088 */  sdc1      $f22, 0x88($sp)
/* 35BFFC E005002C C7B600BC */  lwc1      $f22, 0xbc($sp)
/* 35C000 E0050030 3C02E005 */  lui       $v0, %hi(func_E00501D0)
/* 35C004 E0050034 244201D0 */  addiu     $v0, $v0, %lo(func_E00501D0)
/* 35C008 E0050038 AFA20020 */  sw        $v0, 0x20($sp)
/* 35C00C E005003C 3C02E005 */  lui       $v0, %hi(func_E00501D8)
/* 35C010 E0050040 244201D8 */  addiu     $v0, $v0, %lo(func_E00501D8)
/* 35C014 E0050044 AFA20024 */  sw        $v0, 0x24($sp)
/* 35C018 E0050048 3C02E005 */  lui       $v0, %hi(func_E00502C4)
/* 35C01C E005004C 244202C4 */  addiu     $v0, $v0, %lo(func_E00502C4)
/* 35C020 E0050050 AFA20028 */  sw        $v0, 0x28($sp)
/* 35C024 E0050054 24020028 */  addiu     $v0, $zero, 0x28
/* 35C028 E0050058 AFBF007C */  sw        $ra, 0x7c($sp)
/* 35C02C E005005C AFB10074 */  sw        $s1, 0x74($sp)
/* 35C030 E0050060 AFB00070 */  sw        $s0, 0x70($sp)
/* 35C034 E0050064 F7B40080 */  sdc1      $f20, 0x80($sp)
/* 35C038 E0050068 AFA00018 */  sw        $zero, 0x18($sp)
/* 35C03C E005006C AFA0002C */  sw        $zero, 0x2c($sp)
/* 35C040 E0050070 0C080124 */  jal       func_E0200490
/* 35C044 E0050074 AFA2001C */   sw       $v0, 0x1c($sp)
/* 35C048 E0050078 24040028 */  addiu     $a0, $zero, 0x28
/* 35C04C E005007C 24030001 */  addiu     $v1, $zero, 1
/* 35C050 E0050080 0040802D */  daddu     $s0, $v0, $zero
/* 35C054 E0050084 0C08012C */  jal       func_E02004B0
/* 35C058 E0050088 AE030008 */   sw       $v1, 8($s0)
/* 35C05C E005008C 0040882D */  daddu     $s1, $v0, $zero
/* 35C060 E0050090 16200003 */  bnez      $s1, .LE00500A0
/* 35C064 E0050094 AE02000C */   sw       $v0, 0xc($s0)
.LE0050098:
/* 35C068 E0050098 08014026 */  j         .LE0050098
/* 35C06C E005009C 00000000 */   nop
.LE00500A0:
/* 35C070 E00500A0 3C108007 */  lui       $s0, %hi(gCurrentCameraID)
/* 35C074 E00500A4 26107410 */  addiu     $s0, $s0, %lo(gCurrentCameraID)
/* 35C078 E00500A8 8E030000 */  lw        $v1, ($s0)
/* 35C07C E00500AC AE320000 */  sw        $s2, ($s1)
/* 35C080 E00500B0 00031080 */  sll       $v0, $v1, 2
/* 35C084 E00500B4 00431021 */  addu      $v0, $v0, $v1
/* 35C088 E00500B8 00021080 */  sll       $v0, $v0, 2
/* 35C08C E00500BC 00431023 */  subu      $v0, $v0, $v1
/* 35C090 E00500C0 000218C0 */  sll       $v1, $v0, 3
/* 35C094 E00500C4 00431021 */  addu      $v0, $v0, $v1
/* 35C098 E00500C8 000210C0 */  sll       $v0, $v0, 3
/* 35C09C E00500CC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 35C0A0 E00500D0 00220821 */  addu      $at, $at, $v0
/* 35C0A4 E00500D4 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* 35C0A8 E00500D8 0C080140 */  jal       func_E0200500
/* 35C0AC E00500DC 00000000 */   nop
/* 35C0B0 E00500E0 8E030000 */  lw        $v1, ($s0)
/* 35C0B4 E00500E4 00031080 */  sll       $v0, $v1, 2
/* 35C0B8 E00500E8 00431021 */  addu      $v0, $v0, $v1
/* 35C0BC E00500EC 00021080 */  sll       $v0, $v0, 2
/* 35C0C0 E00500F0 00431023 */  subu      $v0, $v0, $v1
/* 35C0C4 E00500F4 000218C0 */  sll       $v1, $v0, 3
/* 35C0C8 E00500F8 00431021 */  addu      $v0, $v0, $v1
/* 35C0CC E00500FC 000210C0 */  sll       $v0, $v0, 3
/* 35C0D0 E0050100 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 35C0D4 E0050104 00220821 */  addu      $at, $at, $v0
/* 35C0D8 E0050108 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* 35C0DC E005010C 0C080144 */  jal       func_E0200510
/* 35C0E0 E0050110 46000506 */   mov.s    $f20, $f0
/* 35C0E4 E0050114 27A40030 */  addiu     $a0, $sp, 0x30
/* 35C0E8 E0050118 0000382D */  daddu     $a3, $zero, $zero
/* 35C0EC E005011C 4600B107 */  neg.s     $f4, $f22
/* 35C0F0 E0050120 4406A000 */  mfc1      $a2, $f20
/* 35C0F4 E0050124 44052000 */  mfc1      $a1, $f4
/* 35C0F8 E0050128 46000007 */  neg.s     $f0, $f0
/* 35C0FC E005012C 0C080104 */  jal       func_E0200410
/* 35C100 E0050130 E7A00010 */   swc1     $f0, 0x10($sp)
/* 35C104 E0050134 3C014180 */  lui       $at, 0x4180
/* 35C108 E0050138 44810000 */  mtc1      $at, $f0
/* 35C10C E005013C C7A200B8 */  lwc1      $f2, 0xb8($sp)
/* 35C110 E0050140 46001080 */  add.s     $f2, $f2, $f0
/* 35C114 E0050144 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 35C118 E0050148 46020002 */  mul.s     $f0, $f0, $f2
/* 35C11C E005014C 00000000 */  nop
/* 35C120 E0050150 4600C000 */  add.s     $f0, $f24, $f0
/* 35C124 E0050154 E6200004 */  swc1      $f0, 4($s1)
/* 35C128 E0050158 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 35C12C E005015C 46020002 */  mul.s     $f0, $f0, $f2
/* 35C130 E0050160 00000000 */  nop
/* 35C134 E0050164 4600D000 */  add.s     $f0, $f26, $f0
/* 35C138 E0050168 E6200008 */  swc1      $f0, 8($s1)
/* 35C13C E005016C C7A00048 */  lwc1      $f0, 0x48($sp)
/* 35C140 E0050170 46020002 */  mul.s     $f0, $f0, $f2
/* 35C144 E0050174 00000000 */  nop
/* 35C148 E0050178 4600E000 */  add.s     $f0, $f28, $f0
/* 35C14C E005017C E620000C */  swc1      $f0, 0xc($s1)
/* 35C150 E0050180 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 35C154 E0050184 E6200018 */  swc1      $f0, 0x18($s1)
/* 35C158 E0050188 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 35C15C E005018C E620001C */  swc1      $f0, 0x1c($s1)
/* 35C160 E0050190 C7A00048 */  lwc1      $f0, 0x48($sp)
/* 35C164 E0050194 E6360010 */  swc1      $f22, 0x10($s1)
/* 35C168 E0050198 8FA200C0 */  lw        $v0, 0xc0($sp)
/* 35C16C E005019C AE220024 */  sw        $v0, 0x24($s1)
/* 35C170 E00501A0 E6200020 */  swc1      $f0, 0x20($s1)
/* 35C174 E00501A4 8FBF007C */  lw        $ra, 0x7c($sp)
/* 35C178 E00501A8 8FB20078 */  lw        $s2, 0x78($sp)
/* 35C17C E00501AC 8FB10074 */  lw        $s1, 0x74($sp)
/* 35C180 E00501B0 8FB00070 */  lw        $s0, 0x70($sp)
/* 35C184 E00501B4 D7BC00A0 */  ldc1      $f28, 0xa0($sp)
/* 35C188 E00501B8 D7BA0098 */  ldc1      $f26, 0x98($sp)
/* 35C18C E00501BC D7B80090 */  ldc1      $f24, 0x90($sp)
/* 35C190 E00501C0 D7B60088 */  ldc1      $f22, 0x88($sp)
/* 35C194 E00501C4 D7B40080 */  ldc1      $f20, 0x80($sp)
/* 35C198 E00501C8 03E00008 */  jr        $ra
/* 35C19C E00501CC 27BD00A8 */   addiu    $sp, $sp, 0xa8
