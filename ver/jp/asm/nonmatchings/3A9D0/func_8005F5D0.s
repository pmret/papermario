.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F5D0
/* 3A9D0 8005F5D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3A9D4 8005F5D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 3A9D8 8005F5D8 0080902D */  daddu     $s2, $a0, $zero
/* 3A9DC 8005F5DC 00A0302D */  daddu     $a2, $a1, $zero
/* 3A9E0 8005F5E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A9E4 8005F5E4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3A9E8 8005F5E8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3A9EC 8005F5EC AFB10014 */  sw        $s1, 0x14($sp)
/* 3A9F0 8005F5F0 92430006 */  lbu       $v1, 6($s2)
/* 3A9F4 8005F5F4 24130002 */  addiu     $s3, $zero, 2
/* 3A9F8 8005F5F8 10730069 */  beq       $v1, $s3, .L8005F7A0
/* 3A9FC 8005F5FC 0000802D */   daddu    $s0, $zero, $zero
/* 3AA00 8005F600 28620003 */  slti      $v0, $v1, 3
/* 3AA04 8005F604 10400005 */  beqz      $v0, .L8005F61C
/* 3AA08 8005F608 24020001 */   addiu    $v0, $zero, 1
/* 3AA0C 8005F60C 1062000A */  beq       $v1, $v0, .L8005F638
/* 3AA10 8005F610 0200102D */   daddu    $v0, $s0, $zero
/* 3AA14 8005F614 08017DE9 */  j         .L8005F7A4
/* 3AA18 8005F618 00000000 */   nop
.L8005F61C:
/* 3AA1C 8005F61C 24020003 */  addiu     $v0, $zero, 3
/* 3AA20 8005F620 10620018 */  beq       $v1, $v0, .L8005F684
/* 3AA24 8005F624 24020004 */   addiu    $v0, $zero, 4
/* 3AA28 8005F628 10620048 */  beq       $v1, $v0, .L8005F74C
/* 3AA2C 8005F62C 0200102D */   daddu    $v0, $s0, $zero
/* 3AA30 8005F630 08017DE9 */  j         .L8005F7A4
/* 3AA34 8005F634 00000000 */   nop
.L8005F638:
/* 3AA38 8005F638 96420004 */  lhu       $v0, 4($s2)
/* 3AA3C 8005F63C 1040000C */  beqz      $v0, .L8005F670
/* 3AA40 8005F640 00062040 */   sll      $a0, $a2, 1
/* 3AA44 8005F644 00862021 */  addu      $a0, $a0, $a2
/* 3AA48 8005F648 00042080 */  sll       $a0, $a0, 2
/* 3AA4C 8005F64C 00862021 */  addu      $a0, $a0, $a2
/* 3AA50 8005F650 000420C0 */  sll       $a0, $a0, 3
/* 3AA54 8005F654 3C02800E */  lui       $v0, %hi(D_800DAAB8)
/* 3AA58 8005F658 2442AAB8 */  addiu     $v0, $v0, %lo(D_800DAAB8)
/* 3AA5C 8005F65C 00822021 */  addu      $a0, $a0, $v0
/* 3AA60 8005F660 0C019F78 */  jal       func_80067DE0
/* 3AA64 8005F664 0000282D */   daddu    $a1, $zero, $zero
/* 3AA68 8005F668 08017D9D */  j         .L8005F674
/* 3AA6C 8005F66C 0040802D */   daddu    $s0, $v0, $zero
.L8005F670:
/* 3AA70 8005F670 A2530006 */  sb        $s3, 6($s2)
.L8005F674:
/* 3AA74 8005F674 96420004 */  lhu       $v0, 4($s2)
/* 3AA78 8005F678 2442FFFF */  addiu     $v0, $v0, -1
/* 3AA7C 8005F67C 08017DE8 */  j         .L8005F7A0
/* 3AA80 8005F680 A6420004 */   sh       $v0, 4($s2)
.L8005F684:
/* 3AA84 8005F684 96420002 */  lhu       $v0, 2($s2)
/* 3AA88 8005F688 1040001F */  beqz      $v0, .L8005F708
/* 3AA8C 8005F68C 00062040 */   sll      $a0, $a2, 1
/* 3AA90 8005F690 96420004 */  lhu       $v0, 4($s2)
/* 3AA94 8005F694 96430000 */  lhu       $v1, ($s2)
/* 3AA98 8005F698 00431021 */  addu      $v0, $v0, $v1
/* 3AA9C 8005F69C 304300FF */  andi      $v1, $v0, 0xff
/* 3AAA0 8005F6A0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3AAA4 8005F6A4 00021202 */  srl       $v0, $v0, 8
/* 3AAA8 8005F6A8 1040000B */  beqz      $v0, .L8005F6D8
/* 3AAAC 8005F6AC A6430004 */   sh       $v1, 4($s2)
/* 3AAB0 8005F6B0 00062040 */  sll       $a0, $a2, 1
/* 3AAB4 8005F6B4 00862021 */  addu      $a0, $a0, $a2
/* 3AAB8 8005F6B8 00042080 */  sll       $a0, $a0, 2
/* 3AABC 8005F6BC 00862021 */  addu      $a0, $a0, $a2
/* 3AAC0 8005F6C0 000420C0 */  sll       $a0, $a0, 3
/* 3AAC4 8005F6C4 3C02800E */  lui       $v0, %hi(D_800DAAB8)
/* 3AAC8 8005F6C8 2442AAB8 */  addiu     $v0, $v0, %lo(D_800DAAB8)
/* 3AACC 8005F6CC 00822021 */  addu      $a0, $a0, $v0
/* 3AAD0 8005F6D0 08017DBE */  j         .L8005F6F8
/* 3AAD4 8005F6D4 24050001 */   addiu    $a1, $zero, 1
.L8005F6D8:
/* 3AAD8 8005F6D8 00862021 */  addu      $a0, $a0, $a2
/* 3AADC 8005F6DC 00042080 */  sll       $a0, $a0, 2
/* 3AAE0 8005F6E0 00862021 */  addu      $a0, $a0, $a2
/* 3AAE4 8005F6E4 000420C0 */  sll       $a0, $a0, 3
/* 3AAE8 8005F6E8 3C02800E */  lui       $v0, %hi(D_800DAAB8)
/* 3AAEC 8005F6EC 2442AAB8 */  addiu     $v0, $v0, %lo(D_800DAAB8)
/* 3AAF0 8005F6F0 00822021 */  addu      $a0, $a0, $v0
/* 3AAF4 8005F6F4 0000282D */  daddu     $a1, $zero, $zero
.L8005F6F8:
/* 3AAF8 8005F6F8 0C019F78 */  jal       func_80067DE0
/* 3AAFC 8005F6FC 00000000 */   nop
/* 3AB00 8005F700 08017DCF */  j         .L8005F73C
/* 3AB04 8005F704 0040802D */   daddu    $s0, $v0, $zero
.L8005F708:
/* 3AB08 8005F708 00862021 */  addu      $a0, $a0, $a2
/* 3AB0C 8005F70C 00042080 */  sll       $a0, $a0, 2
/* 3AB10 8005F710 00862021 */  addu      $a0, $a0, $a2
/* 3AB14 8005F714 000420C0 */  sll       $a0, $a0, 3
/* 3AB18 8005F718 3C02800E */  lui       $v0, %hi(D_800DAAB8)
/* 3AB1C 8005F71C 2442AAB8 */  addiu     $v0, $v0, %lo(D_800DAAB8)
/* 3AB20 8005F720 00822021 */  addu      $a0, $a0, $v0
/* 3AB24 8005F724 0C019F78 */  jal       func_80067DE0
/* 3AB28 8005F728 0000282D */   daddu    $a1, $zero, $zero
/* 3AB2C 8005F72C 0040802D */  daddu     $s0, $v0, $zero
/* 3AB30 8005F730 24020001 */  addiu     $v0, $zero, 1
/* 3AB34 8005F734 A2420006 */  sb        $v0, 6($s2)
/* 3AB38 8005F738 A6530004 */  sh        $s3, 4($s2)
.L8005F73C:
/* 3AB3C 8005F73C 96420002 */  lhu       $v0, 2($s2)
/* 3AB40 8005F740 2442FFFF */  addiu     $v0, $v0, -1
/* 3AB44 8005F744 08017DE8 */  j         .L8005F7A0
/* 3AB48 8005F748 A6420002 */   sh       $v0, 2($s2)
.L8005F74C:
/* 3AB4C 8005F74C 3C04800E */  lui       $a0, %hi(D_800DAC58)
/* 3AB50 8005F750 2484AC58 */  addiu     $a0, $a0, %lo(D_800DAC58)
/* 3AB54 8005F754 00061040 */  sll       $v0, $a2, 1
/* 3AB58 8005F758 00461021 */  addu      $v0, $v0, $a2
/* 3AB5C 8005F75C 00021080 */  sll       $v0, $v0, 2
/* 3AB60 8005F760 00461021 */  addu      $v0, $v0, $a2
/* 3AB64 8005F764 000210C0 */  sll       $v0, $v0, 3
/* 3AB68 8005F768 3C03800E */  lui       $v1, %hi(D_800DAAB8)
/* 3AB6C 8005F76C 2463AAB8 */  addiu     $v1, $v1, %lo(D_800DAAB8)
/* 3AB70 8005F770 00438821 */  addu      $s1, $v0, $v1
/* 3AB74 8005F774 0C019FC9 */  jal       func_80067F24
/* 3AB78 8005F778 0220282D */   daddu    $a1, $s1, $zero
/* 3AB7C 8005F77C 0040802D */  daddu     $s0, $v0, $zero
/* 3AB80 8005F780 16000005 */  bnez      $s0, .L8005F798
/* 3AB84 8005F784 24020001 */   addiu    $v0, $zero, 1
/* 3AB88 8005F788 0220202D */  daddu     $a0, $s1, $zero
/* 3AB8C 8005F78C 0C019F78 */  jal       func_80067DE0
/* 3AB90 8005F790 0000282D */   daddu    $a1, $zero, $zero
/* 3AB94 8005F794 24020001 */  addiu     $v0, $zero, 1
.L8005F798:
/* 3AB98 8005F798 A2420006 */  sb        $v0, 6($s2)
/* 3AB9C 8005F79C A6530004 */  sh        $s3, 4($s2)
.L8005F7A0:
/* 3ABA0 8005F7A0 0200102D */  daddu     $v0, $s0, $zero
.L8005F7A4:
/* 3ABA4 8005F7A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3ABA8 8005F7A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3ABAC 8005F7AC 8FB20018 */  lw        $s2, 0x18($sp)
/* 3ABB0 8005F7B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 3ABB4 8005F7B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 3ABB8 8005F7B8 03E00008 */  jr        $ra
/* 3ABBC 8005F7BC 27BD0028 */   addiu    $sp, $sp, 0x28
