.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPfsFileState
/* 44020 80068C20 27BDFEB0 */  addiu     $sp, $sp, -0x150
/* 44024 80068C24 AFB10134 */  sw        $s1, 0x134($sp)
/* 44028 80068C28 00808821 */  addu      $s1, $a0, $zero
/* 4402C 80068C2C AFB00130 */  sw        $s0, 0x130($sp)
/* 44030 80068C30 00A08021 */  addu      $s0, $a1, $zero
/* 44034 80068C34 AFBF0148 */  sw        $ra, 0x148($sp)
/* 44038 80068C38 AFB50144 */  sw        $s5, 0x144($sp)
/* 4403C 80068C3C AFB40140 */  sw        $s4, 0x140($sp)
/* 44040 80068C40 AFB3013C */  sw        $s3, 0x13c($sp)
/* 44044 80068C44 AFB20138 */  sw        $s2, 0x138($sp)
/* 44048 80068C48 8E220050 */  lw        $v0, 0x50($s1)
/* 4404C 80068C4C 00101FC2 */  srl       $v1, $s0, 0x1f
/* 44050 80068C50 0202102A */  slt       $v0, $s0, $v0
/* 44054 80068C54 38420001 */  xori      $v0, $v0, 1
/* 44058 80068C58 00431025 */  or        $v0, $v0, $v1
/* 4405C 80068C5C 1440001F */  bnez      $v0, .L80068CDC
/* 44060 80068C60 00C0A021 */   addu     $s4, $a2, $zero
/* 44064 80068C64 8E220000 */  lw        $v0, ($s1)
/* 44068 80068C68 30420001 */  andi      $v0, $v0, 1
/* 4406C 80068C6C 10400048 */  beqz      $v0, .L80068D90
/* 44070 80068C70 24020005 */   addiu    $v0, $zero, 5
/* 44074 80068C74 0C01A775 */  jal       __osCheckId
/* 44078 80068C78 02202021 */   addu     $a0, $s1, $zero
/* 4407C 80068C7C 14400044 */  bnez      $v0, .L80068D90
/* 44080 80068C80 00000000 */   nop
/* 44084 80068C84 92220065 */  lbu       $v0, 0x65($s1)
/* 44088 80068C88 10400005 */  beqz      $v0, .L80068CA0
/* 4408C 80068C8C 02202021 */   addu     $a0, $s1, $zero
/* 44090 80068C90 0C01A5B4 */  jal       __osPfsSelectBank
/* 44094 80068C94 00002821 */   addu     $a1, $zero, $zero
/* 44098 80068C98 1440003D */  bnez      $v0, .L80068D90
/* 4409C 80068C9C 00000000 */   nop
.L80068CA0:
/* 440A0 80068CA0 8E240004 */  lw        $a0, 4($s1)
/* 440A4 80068CA4 8E26005C */  lw        $a2, 0x5c($s1)
/* 440A8 80068CA8 8E250008 */  lw        $a1, 8($s1)
/* 440AC 80068CAC 27A70110 */  addiu     $a3, $sp, 0x110
/* 440B0 80068CB0 00D03021 */  addu      $a2, $a2, $s0
/* 440B4 80068CB4 0C01A874 */  jal       __osContRamRead
/* 440B8 80068CB8 30C6FFFF */   andi     $a2, $a2, 0xffff
/* 440BC 80068CBC 14400034 */  bnez      $v0, .L80068D90
/* 440C0 80068CC0 00000000 */   nop
/* 440C4 80068CC4 97A20114 */  lhu       $v0, 0x114($sp)
/* 440C8 80068CC8 10400031 */  beqz      $v0, .L80068D90
/* 440CC 80068CCC 24020005 */   addiu    $v0, $zero, 5
/* 440D0 80068CD0 8FA20110 */  lw        $v0, 0x110($sp)
/* 440D4 80068CD4 14400003 */  bnez      $v0, .L80068CE4
/* 440D8 80068CD8 00009821 */   addu     $s3, $zero, $zero
.L80068CDC:
/* 440DC 80068CDC 0801A364 */  j         .L80068D90
/* 440E0 80068CE0 24020005 */   addiu    $v0, $zero, 5
.L80068CE4:
/* 440E4 80068CE4 97B00116 */  lhu       $s0, 0x116($sp)
/* 440E8 80068CE8 241200FF */  addiu     $s2, $zero, 0xff
/* 440EC 80068CEC 27B50010 */  addiu     $s5, $sp, 0x10
.L80068CF0:
/* 440F0 80068CF0 8E220060 */  lw        $v0, 0x60($s1)
/* 440F4 80068CF4 3203FFFF */  andi      $v1, $s0, 0xffff
/* 440F8 80068CF8 0062102A */  slt       $v0, $v1, $v0
/* 440FC 80068CFC 14400010 */  bnez      $v0, .L80068D40
/* 44100 80068D00 00031202 */   srl      $v0, $v1, 8
/* 44104 80068D04 304700FF */  andi      $a3, $v0, 0xff
/* 44108 80068D08 10F20007 */  beq       $a3, $s2, .L80068D28
/* 4410C 80068D0C 02202021 */   addu     $a0, $s1, $zero
/* 44110 80068D10 00409021 */  addu      $s2, $v0, $zero
/* 44114 80068D14 27A50010 */  addiu     $a1, $sp, 0x10
/* 44118 80068D18 0C01A7A3 */  jal       __osPfsRWInode
/* 4411C 80068D1C 00003021 */   addu     $a2, $zero, $zero
/* 44120 80068D20 1440001B */  bnez      $v0, .L80068D90
/* 44124 80068D24 00000000 */   nop
.L80068D28:
/* 44128 80068D28 320200FF */  andi      $v0, $s0, 0xff
/* 4412C 80068D2C 00021040 */  sll       $v0, $v0, 1
/* 44130 80068D30 00551021 */  addu      $v0, $v0, $s5
/* 44134 80068D34 94500000 */  lhu       $s0, ($v0)
/* 44138 80068D38 0801A33C */  j         .L80068CF0
/* 4413C 80068D3C 26730001 */   addiu    $s3, $s3, 1
.L80068D40:
/* 44140 80068D40 24020001 */  addiu     $v0, $zero, 1
/* 44144 80068D44 14620012 */  bne       $v1, $v0, .L80068D90
/* 44148 80068D48 24020003 */   addiu    $v0, $zero, 3
/* 4414C 80068D4C 00131200 */  sll       $v0, $s3, 8
/* 44150 80068D50 AE820000 */  sw        $v0, ($s4)
/* 44154 80068D54 97A20114 */  lhu       $v0, 0x114($sp)
/* 44158 80068D58 27A40120 */  addiu     $a0, $sp, 0x120
/* 4415C 80068D5C A6820008 */  sh        $v0, 8($s4)
/* 44160 80068D60 8FA20110 */  lw        $v0, 0x110($sp)
/* 44164 80068D64 2685000E */  addiu     $a1, $s4, 0xe
/* 44168 80068D68 24060010 */  addiu     $a2, $zero, 0x10
/* 4416C 80068D6C 0C019194 */  jal       bcopy
/* 44170 80068D70 AE820004 */   sw       $v0, 4($s4)
/* 44174 80068D74 27A4011C */  addiu     $a0, $sp, 0x11c
/* 44178 80068D78 2685000A */  addiu     $a1, $s4, 0xa
/* 4417C 80068D7C 0C019194 */  jal       bcopy
/* 44180 80068D80 24060004 */   addiu    $a2, $zero, 4
/* 44184 80068D84 8E240004 */  lw        $a0, 4($s1)
/* 44188 80068D88 0C01A530 */  jal       __osPfsGetStatus
/* 4418C 80068D8C 8E250008 */   lw       $a1, 8($s1)
.L80068D90:
/* 44190 80068D90 8FBF0148 */  lw        $ra, 0x148($sp)
/* 44194 80068D94 8FB50144 */  lw        $s5, 0x144($sp)
/* 44198 80068D98 8FB40140 */  lw        $s4, 0x140($sp)
/* 4419C 80068D9C 8FB3013C */  lw        $s3, 0x13c($sp)
/* 441A0 80068DA0 8FB20138 */  lw        $s2, 0x138($sp)
/* 441A4 80068DA4 8FB10134 */  lw        $s1, 0x134($sp)
/* 441A8 80068DA8 8FB00130 */  lw        $s0, 0x130($sp)
/* 441AC 80068DAC 03E00008 */  jr        $ra
/* 441B0 80068DB0 27BD0150 */   addiu    $sp, $sp, 0x150
/* 441B4 80068DB4 00000000 */  nop
/* 441B8 80068DB8 00000000 */  nop
/* 441BC 80068DBC 00000000 */  nop
