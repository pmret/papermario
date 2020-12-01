.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel _load_string
/* BC01C 8012591C 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* BC020 80125920 AFB70054 */  sw        $s7, 0x54($sp)
/* BC024 80125924 0080B82D */  daddu     $s7, $a0, $zero
/* BC028 80125928 AFBE0058 */  sw        $fp, 0x58($sp)
/* BC02C 8012592C 00A0F02D */  daddu     $fp, $a1, $zero
/* BC030 80125930 AFBF005C */  sw        $ra, 0x5c($sp)
/* BC034 80125934 AFB60050 */  sw        $s6, 0x50($sp)
/* BC038 80125938 AFB5004C */  sw        $s5, 0x4c($sp)
/* BC03C 8012593C AFB40048 */  sw        $s4, 0x48($sp)
/* BC040 80125940 AFB30044 */  sw        $s3, 0x44($sp)
/* BC044 80125944 AFB20040 */  sw        $s2, 0x40($sp)
/* BC048 80125948 AFB1003C */  sw        $s1, 0x3c($sp)
/* BC04C 8012594C AFB00038 */  sw        $s0, 0x38($sp)
/* BC050 80125950 12E00038 */  beqz      $s7, .L80125A34
/* BC054 80125954 AFA60068 */   sw       $a2, 0x68($sp)
/* BC058 80125958 06E00004 */  bltz      $s7, .L8012596C
/* BC05C 8012595C 02E0982D */   daddu    $s3, $s7, $zero
/* BC060 80125960 0C049623 */  jal       load_message_to_buffer
/* BC064 80125964 02E0202D */   daddu    $a0, $s7, $zero
/* BC068 80125968 0040982D */  daddu     $s3, $v0, $zero
.L8012596C:
/* BC06C 8012596C 0000182D */  daddu     $v1, $zero, $zero
/* BC070 80125970 27B10020 */  addiu     $s1, $sp, 0x20
/* BC074 80125974 27B20024 */  addiu     $s2, $sp, 0x24
/* BC078 80125978 27B40028 */  addiu     $s4, $sp, 0x28
/* BC07C 8012597C 27B5002C */  addiu     $s5, $sp, 0x2c
/* BC080 80125980 27B60030 */  addiu     $s6, $sp, 0x30
/* BC084 80125984 3C108015 */  lui       $s0, %hi(D_80154C30)
/* BC088 80125988 26104C30 */  addiu     $s0, $s0, %lo(D_80154C30)
.L8012598C:
/* BC08C 8012598C 8E0204FC */  lw        $v0, 0x4fc($s0)
/* BC090 80125990 30420002 */  andi      $v0, $v0, 2
/* BC094 80125994 14400024 */  bnez      $v0, .L80125A28
/* BC098 80125998 24630001 */   addiu    $v1, $v1, 1
/* BC09C 8012599C 0200202D */  daddu     $a0, $s0, $zero
/* BC0A0 801259A0 8FA60068 */  lw        $a2, 0x68($sp)
/* BC0A4 801259A4 0C0495A9 */  jal       initialize_printer
/* BC0A8 801259A8 24050001 */   addiu    $a1, $zero, 1
/* BC0AC 801259AC 02E0202D */  daddu     $a0, $s7, $zero
/* BC0B0 801259B0 0220282D */  daddu     $a1, $s1, $zero
/* BC0B4 801259B4 0240302D */  daddu     $a2, $s2, $zero
/* BC0B8 801259B8 24080001 */  addiu     $t0, $zero, 1
/* BC0BC 801259BC 8E0204FC */  lw        $v0, 0x4fc($s0)
/* BC0C0 801259C0 0280382D */  daddu     $a3, $s4, $zero
/* BC0C4 801259C4 A20804F8 */  sb        $t0, 0x4f8($s0)
/* BC0C8 801259C8 AE130000 */  sw        $s3, ($s0)
/* BC0CC 801259CC AE040008 */  sw        $a0, 8($s0)
/* BC0D0 801259D0 34420002 */  ori       $v0, $v0, 2
/* BC0D4 801259D4 AE0204FC */  sw        $v0, 0x4fc($s0)
/* BC0D8 801259D8 AFB50010 */  sw        $s5, 0x10($sp)
/* BC0DC 801259DC AFB60014 */  sw        $s6, 0x14($sp)
/* BC0E0 801259E0 AFA00018 */  sw        $zero, 0x18($sp)
/* BC0E4 801259E4 0C0497DA */  jal       get_string_properties
/* BC0E8 801259E8 AFA0001C */   sw       $zero, 0x1c($sp)
/* BC0EC 801259EC 96220002 */  lhu       $v0, 2($s1)
/* BC0F0 801259F0 A6020536 */  sh        $v0, 0x536($s0)
/* BC0F4 801259F4 96420002 */  lhu       $v0, 2($s2)
/* BC0F8 801259F8 A6020538 */  sh        $v0, 0x538($s0)
/* BC0FC 801259FC 92820003 */  lbu       $v0, 3($s4)
/* BC100 80125A00 A202053A */  sb        $v0, 0x53a($s0)
/* BC104 80125A04 92A20003 */  lbu       $v0, 3($s5)
/* BC108 80125A08 A202053B */  sb        $v0, 0x53b($s0)
/* BC10C 80125A0C 92C20003 */  lbu       $v0, 3($s6)
/* BC110 80125A10 AE1E0504 */  sw        $fp, 0x504($s0)
/* BC114 80125A14 13C00002 */  beqz      $fp, .L80125A20
/* BC118 80125A18 A202053C */   sb       $v0, 0x53c($s0)
/* BC11C 80125A1C AFC00000 */  sw        $zero, ($fp)
.L80125A20:
/* BC120 80125A20 0804968E */  j         .L80125A38
/* BC124 80125A24 0200102D */   daddu    $v0, $s0, $zero
.L80125A28:
/* BC128 80125A28 28620003 */  slti      $v0, $v1, 3
/* BC12C 80125A2C 1440FFD7 */  bnez      $v0, .L8012598C
/* BC130 80125A30 26100558 */   addiu    $s0, $s0, 0x558
.L80125A34:
/* BC134 80125A34 0000102D */  daddu     $v0, $zero, $zero
.L80125A38:
/* BC138 80125A38 8FBF005C */  lw        $ra, 0x5c($sp)
/* BC13C 80125A3C 8FBE0058 */  lw        $fp, 0x58($sp)
/* BC140 80125A40 8FB70054 */  lw        $s7, 0x54($sp)
/* BC144 80125A44 8FB60050 */  lw        $s6, 0x50($sp)
/* BC148 80125A48 8FB5004C */  lw        $s5, 0x4c($sp)
/* BC14C 80125A4C 8FB40048 */  lw        $s4, 0x48($sp)
/* BC150 80125A50 8FB30044 */  lw        $s3, 0x44($sp)
/* BC154 80125A54 8FB20040 */  lw        $s2, 0x40($sp)
/* BC158 80125A58 8FB1003C */  lw        $s1, 0x3c($sp)
/* BC15C 80125A5C 8FB00038 */  lw        $s0, 0x38($sp)
/* BC160 80125A60 03E00008 */  jr        $ra
/* BC164 80125A64 27BD0060 */   addiu    $sp, $sp, 0x60
