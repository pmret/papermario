.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPfsDeleteFile
/* 439C0 800685C0 27BDFEA0 */  addiu     $sp, $sp, -0x160
/* 439C4 800685C4 AFB10144 */  sw        $s1, 0x144($sp)
/* 439C8 800685C8 00808821 */  addu      $s1, $a0, $zero
/* 439CC 800685CC 8FA80170 */  lw        $t0, 0x170($sp)
/* 439D0 800685D0 30A5FFFF */  andi      $a1, $a1, 0xffff
/* 439D4 800685D4 2CA20001 */  sltiu     $v0, $a1, 1
/* 439D8 800685D8 2CC30001 */  sltiu     $v1, $a2, 1
/* 439DC 800685DC 00431025 */  or        $v0, $v0, $v1
/* 439E0 800685E0 AFBF0158 */  sw        $ra, 0x158($sp)
/* 439E4 800685E4 AFB50154 */  sw        $s5, 0x154($sp)
/* 439E8 800685E8 AFB40150 */  sw        $s4, 0x150($sp)
/* 439EC 800685EC AFB3014C */  sw        $s3, 0x14c($sp)
/* 439F0 800685F0 AFB20148 */  sw        $s2, 0x148($sp)
/* 439F4 800685F4 10400003 */  beqz      $v0, .L80068604
/* 439F8 800685F8 AFB00140 */   sw       $s0, 0x140($sp)
/* 439FC 800685FC 0801A1D2 */  j         .L80068748
/* 43A00 80068600 24020005 */   addiu    $v0, $zero, 5
.L80068604:
/* 43A04 80068604 02202021 */  addu      $a0, $s1, $zero
/* 43A08 80068608 27A20138 */  addiu     $v0, $sp, 0x138
/* 43A0C 8006860C AFA80010 */  sw        $t0, 0x10($sp)
/* 43A10 80068610 0C01A370 */  jal       osPfsFindFile
/* 43A14 80068614 AFA20014 */   sw       $v0, 0x14($sp)
/* 43A18 80068618 1440004B */  bnez      $v0, .L80068748
/* 43A1C 8006861C 00000000 */   nop
/* 43A20 80068620 92220065 */  lbu       $v0, 0x65($s1)
/* 43A24 80068624 10400005 */  beqz      $v0, .L8006863C
/* 43A28 80068628 02202021 */   addu     $a0, $s1, $zero
/* 43A2C 8006862C 0C01A5B4 */  jal       osPfsSelectBank
/* 43A30 80068630 00002821 */   addu     $a1, $zero, $zero
/* 43A34 80068634 14400044 */  bnez      $v0, .L80068748
/* 43A38 80068638 00000000 */   nop
.L8006863C:
/* 43A3C 8006863C 8E240004 */  lw        $a0, 4($s1)
/* 43A40 80068640 8E26005C */  lw        $a2, 0x5c($s1)
/* 43A44 80068644 8FA20138 */  lw        $v0, 0x138($sp)
/* 43A48 80068648 8E250008 */  lw        $a1, 8($s1)
/* 43A4C 8006864C 27A70118 */  addiu     $a3, $sp, 0x118
/* 43A50 80068650 00C23021 */  addu      $a2, $a2, $v0
/* 43A54 80068654 0C01A874 */  jal       osContRamRead
/* 43A58 80068658 30C6FFFF */   andi     $a2, $a2, 0xffff
/* 43A5C 8006865C 1440003A */  bnez      $v0, .L80068748
/* 43A60 80068660 00000000 */   nop
/* 43A64 80068664 93B3011E */  lbu       $s3, 0x11e($sp)
/* 43A68 80068668 92220064 */  lbu       $v0, 0x64($s1)
/* 43A6C 8006866C 93B2011F */  lbu       $s2, 0x11f($sp)
/* 43A70 80068670 327000FF */  andi      $s0, $s3, 0xff
/* 43A74 80068674 0202102B */  sltu      $v0, $s0, $v0
/* 43A78 80068678 10400032 */  beqz      $v0, .L80068744
/* 43A7C 8006867C 27B4013C */   addiu    $s4, $sp, 0x13c
/* 43A80 80068680 24150001 */  addiu     $s5, $zero, 1
/* 43A84 80068684 02202021 */  addu      $a0, $s1, $zero
.L80068688:
/* 43A88 80068688 27A50018 */  addiu     $a1, $sp, 0x18
/* 43A8C 8006868C 00003021 */  addu      $a2, $zero, $zero
/* 43A90 80068690 0C01A7A3 */  jal       __osPfsRWInode
/* 43A94 80068694 02003821 */   addu     $a3, $s0, $zero
/* 43A98 80068698 1440002B */  bnez      $v0, .L80068748
/* 43A9C 8006869C 02202021 */   addu     $a0, $s1, $zero
/* 43AA0 800686A0 AFB40010 */  sw        $s4, 0x10($sp)
/* 43AA4 800686A4 27A50018 */  addiu     $a1, $sp, 0x18
/* 43AA8 800686A8 02403021 */  addu      $a2, $s2, $zero
/* 43AAC 800686AC 0C01A1DB */  jal       osPfsReleasePages
/* 43AB0 800686B0 02003821 */   addu     $a3, $s0, $zero
/* 43AB4 800686B4 14400024 */  bnez      $v0, .L80068748
/* 43AB8 800686B8 02202021 */   addu     $a0, $s1, $zero
/* 43ABC 800686BC 27A50018 */  addiu     $a1, $sp, 0x18
/* 43AC0 800686C0 24060001 */  addiu     $a2, $zero, 1
/* 43AC4 800686C4 0C01A7A3 */  jal       __osPfsRWInode
/* 43AC8 800686C8 02003821 */   addu     $a3, $s0, $zero
/* 43ACC 800686CC 1440001E */  bnez      $v0, .L80068748
/* 43AD0 800686D0 00000000 */   nop
/* 43AD4 800686D4 97A2013C */  lhu       $v0, 0x13c($sp)
/* 43AD8 800686D8 10550008 */  beq       $v0, $s5, .L800686FC
/* 43ADC 800686DC 00000000 */   nop
/* 43AE0 800686E0 93B3013C */  lbu       $s3, 0x13c($sp)
/* 43AE4 800686E4 92220064 */  lbu       $v0, 0x64($s1)
/* 43AE8 800686E8 93B2013D */  lbu       $s2, 0x13d($sp)
/* 43AEC 800686EC 327000FF */  andi      $s0, $s3, 0xff
/* 43AF0 800686F0 0202102B */  sltu      $v0, $s0, $v0
/* 43AF4 800686F4 1440FFE4 */  bnez      $v0, .L80068688
/* 43AF8 800686F8 02202021 */   addu     $a0, $s1, $zero
.L800686FC:
/* 43AFC 800686FC 92220064 */  lbu       $v0, 0x64($s1)
/* 43B00 80068700 0262102B */  sltu      $v0, $s3, $v0
/* 43B04 80068704 1040000F */  beqz      $v0, .L80068744
/* 43B08 80068708 27B00118 */   addiu    $s0, $sp, 0x118
/* 43B0C 8006870C 02002021 */  addu      $a0, $s0, $zero
/* 43B10 80068710 0C01925C */  jal       bzero
/* 43B14 80068714 24050020 */   addiu    $a1, $zero, 0x20
/* 43B18 80068718 8E26005C */  lw        $a2, 0x5c($s1)
/* 43B1C 8006871C 8FA20138 */  lw        $v0, 0x138($sp)
/* 43B20 80068720 AFA00010 */  sw        $zero, 0x10($sp)
/* 43B24 80068724 8E240004 */  lw        $a0, 4($s1)
/* 43B28 80068728 8E250008 */  lw        $a1, 8($s1)
/* 43B2C 8006872C 02003821 */  addu      $a3, $s0, $zero
/* 43B30 80068730 00C23021 */  addu      $a2, $a2, $v0
/* 43B34 80068734 0C01A8F0 */  jal       osContRamWrite
/* 43B38 80068738 30C6FFFF */   andi     $a2, $a2, 0xffff
/* 43B3C 8006873C 0801A1D2 */  j         .L80068748
/* 43B40 80068740 00000000 */   nop
.L80068744:
/* 43B44 80068744 24020003 */  addiu     $v0, $zero, 3
.L80068748:
/* 43B48 80068748 8FBF0158 */  lw        $ra, 0x158($sp)
/* 43B4C 8006874C 8FB50154 */  lw        $s5, 0x154($sp)
/* 43B50 80068750 8FB40150 */  lw        $s4, 0x150($sp)
/* 43B54 80068754 8FB3014C */  lw        $s3, 0x14c($sp)
/* 43B58 80068758 8FB20148 */  lw        $s2, 0x148($sp)
/* 43B5C 8006875C 8FB10144 */  lw        $s1, 0x144($sp)
/* 43B60 80068760 8FB00140 */  lw        $s0, 0x140($sp)
/* 43B64 80068764 03E00008 */  jr        $ra
/* 43B68 80068768 27BD0160 */   addiu    $sp, $sp, 0x160
