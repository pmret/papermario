.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C95A0
/* EDF50 802C95A0 27BDFE70 */  addiu     $sp, $sp, -0x190
/* EDF54 802C95A4 AFB40188 */  sw        $s4, 0x188($sp)
/* EDF58 802C95A8 0080A02D */  daddu     $s4, $a0, $zero
/* EDF5C 802C95AC AFB30184 */  sw        $s3, 0x184($sp)
/* EDF60 802C95B0 00A0982D */  daddu     $s3, $a1, $zero
/* EDF64 802C95B4 AFBF018C */  sw        $ra, 0x18c($sp)
/* EDF68 802C95B8 AFB20180 */  sw        $s2, 0x180($sp)
/* EDF6C 802C95BC AFB1017C */  sw        $s1, 0x17c($sp)
/* EDF70 802C95C0 AFB00178 */  sw        $s0, 0x178($sp)
/* EDF74 802C95C4 8E62000C */  lw        $v0, 0xc($s3)
/* EDF78 802C95C8 2411FFFF */  addiu     $s1, $zero, -1
/* EDF7C 802C95CC 8C450000 */  lw        $a1, ($v0)
/* EDF80 802C95D0 0C0B1EAF */  jal       get_variable
/* EDF84 802C95D4 0260202D */   daddu    $a0, $s3, $zero
/* EDF88 802C95D8 0040282D */  daddu     $a1, $v0, $zero
/* EDF8C 802C95DC 3C06800A */  lui       $a2, %hi(D_8009A5F4)
/* EDF90 802C95E0 8CC6A5F4 */  lw        $a2, %lo(D_8009A5F4)($a2)
/* EDF94 802C95E4 00051080 */  sll       $v0, $a1, 2
/* EDF98 802C95E8 00462021 */  addu      $a0, $v0, $a2
/* EDF9C 802C95EC 90830000 */  lbu       $v1, ($a0)
/* EDFA0 802C95F0 286200FF */  slti      $v0, $v1, 0xff
/* EDFA4 802C95F4 10400004 */  beqz      $v0, .L802C9608
/* EDFA8 802C95F8 0220902D */   daddu    $s2, $s1, $zero
/* EDFAC 802C95FC 0060902D */  daddu     $s2, $v1, $zero
/* EDFB0 802C9600 080B2597 */  j         .L802C965C
/* EDFB4 802C9604 0240882D */   daddu    $s1, $s2, $zero
.L802C9608:
/* EDFB8 802C9608 24B0FFFF */  addiu     $s0, $a1, -1
/* EDFBC 802C960C 90850001 */  lbu       $a1, 1($a0)
/* EDFC0 802C9610 06000013 */  bltz      $s0, .L802C9660
/* EDFC4 802C9614 27A20010 */   addiu    $v0, $sp, 0x10
/* EDFC8 802C9618 2407FFFF */  addiu     $a3, $zero, -1
/* EDFCC 802C961C 00101080 */  sll       $v0, $s0, 2
/* EDFD0 802C9620 00462021 */  addu      $a0, $v0, $a2
.L802C9624:
/* EDFD4 802C9624 90820001 */  lbu       $v0, 1($a0)
/* EDFD8 802C9628 00A2102A */  slt       $v0, $a1, $v0
/* EDFDC 802C962C 1040000C */  beqz      $v0, .L802C9660
/* EDFE0 802C9630 27A20010 */   addiu    $v0, $sp, 0x10
/* EDFE4 802C9634 90830000 */  lbu       $v1, ($a0)
/* EDFE8 802C9638 286200FF */  slti      $v0, $v1, 0xff
/* EDFEC 802C963C 50400005 */  beql      $v0, $zero, .L802C9654
/* EDFF0 802C9640 2610FFFF */   addiu    $s0, $s0, -1
/* EDFF4 802C9644 52470001 */  beql      $s2, $a3, .L802C964C
/* EDFF8 802C9648 0060902D */   daddu    $s2, $v1, $zero
.L802C964C:
/* EDFFC 802C964C 0060882D */  daddu     $s1, $v1, $zero
/* EE000 802C9650 2610FFFF */  addiu     $s0, $s0, -1
.L802C9654:
/* EE004 802C9654 0601FFF3 */  bgez      $s0, .L802C9624
/* EE008 802C9658 2484FFFC */   addiu    $a0, $a0, -4
.L802C965C:
/* EE00C 802C965C 27A20010 */  addiu     $v0, $sp, 0x10
.L802C9660:
/* EE010 802C9660 0260202D */  daddu     $a0, $s3, $zero
/* EE014 802C9664 24830160 */  addiu     $v1, $a0, 0x160
.L802C9668:
/* EE018 802C9668 8C880000 */  lw        $t0, ($a0)
/* EE01C 802C966C 8C890004 */  lw        $t1, 4($a0)
/* EE020 802C9670 8C8A0008 */  lw        $t2, 8($a0)
/* EE024 802C9674 8C8B000C */  lw        $t3, 0xc($a0)
/* EE028 802C9678 AC480000 */  sw        $t0, ($v0)
/* EE02C 802C967C AC490004 */  sw        $t1, 4($v0)
/* EE030 802C9680 AC4A0008 */  sw        $t2, 8($v0)
/* EE034 802C9684 AC4B000C */  sw        $t3, 0xc($v0)
/* EE038 802C9688 24840010 */  addiu     $a0, $a0, 0x10
/* EE03C 802C968C 1483FFF6 */  bne       $a0, $v1, .L802C9668
/* EE040 802C9690 24420010 */   addiu    $v0, $v0, 0x10
/* EE044 802C9694 0220802D */  daddu     $s0, $s1, $zero
/* EE048 802C9698 8C880000 */  lw        $t0, ($a0)
/* EE04C 802C969C 8C890004 */  lw        $t1, 4($a0)
/* EE050 802C96A0 AC480000 */  sw        $t0, ($v0)
/* EE054 802C96A4 AC490004 */  sw        $t1, 4($v0)
/* EE058 802C96A8 8FB1001C */  lw        $s1, 0x1c($sp)
/* EE05C 802C96AC 0250102A */  slt       $v0, $s2, $s0
/* EE060 802C96B0 8E330000 */  lw        $s3, ($s1)
/* EE064 802C96B4 54400011 */  bnel      $v0, $zero, .L802C96FC
/* EE068 802C96B8 AE330000 */   sw       $s3, ($s1)
/* EE06C 802C96BC 27A40010 */  addiu     $a0, $sp, 0x10
.L802C96C0:
/* EE070 802C96C0 3C038015 */  lui       $v1, %hi(gCurrentModelListPtr)
/* EE074 802C96C4 8C6312CC */  lw        $v1, %lo(gCurrentModelListPtr)($v1)
/* EE078 802C96C8 00101080 */  sll       $v0, $s0, 2
/* EE07C 802C96CC 00431021 */  addu      $v0, $v0, $v1
/* EE080 802C96D0 8C420000 */  lw        $v0, ($v0)
/* EE084 802C96D4 24050001 */  addiu     $a1, $zero, 1
/* EE088 802C96D8 AFB1001C */  sw        $s1, 0x1c($sp)
/* EE08C 802C96DC 94420002 */  lhu       $v0, 2($v0)
/* EE090 802C96E0 02058021 */  addu      $s0, $s0, $a1
/* EE094 802C96E4 0280F809 */  jalr      $s4
/* EE098 802C96E8 AE220000 */   sw       $v0, ($s1)
/* EE09C 802C96EC 0250102A */  slt       $v0, $s2, $s0
/* EE0A0 802C96F0 1040FFF3 */  beqz      $v0, .L802C96C0
/* EE0A4 802C96F4 27A40010 */   addiu    $a0, $sp, 0x10
/* EE0A8 802C96F8 AE330000 */  sw        $s3, ($s1)
.L802C96FC:
/* EE0AC 802C96FC 8FBF018C */  lw        $ra, 0x18c($sp)
/* EE0B0 802C9700 8FB40188 */  lw        $s4, 0x188($sp)
/* EE0B4 802C9704 8FB30184 */  lw        $s3, 0x184($sp)
/* EE0B8 802C9708 8FB20180 */  lw        $s2, 0x180($sp)
/* EE0BC 802C970C 8FB1017C */  lw        $s1, 0x17c($sp)
/* EE0C0 802C9710 8FB00178 */  lw        $s0, 0x178($sp)
/* EE0C4 802C9714 03E00008 */  jr        $ra
/* EE0C8 802C9718 27BD0190 */   addiu    $sp, $sp, 0x190
