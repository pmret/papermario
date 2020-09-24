.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ShowChoice
/* F551C 802D0B6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F5520 802D0B70 AFB00010 */  sw        $s0, 0x10($sp)
/* F5524 802D0B74 0080802D */  daddu     $s0, $a0, $zero
/* F5528 802D0B78 AFBF0014 */  sw        $ra, 0x14($sp)
/* F552C 802D0B7C 10A00009 */  beqz      $a1, .L802D0BA4
/* F5530 802D0B80 8E02000C */   lw       $v0, 0xc($s0)
/* F5534 802D0B84 0C0B1EAF */  jal       get_variable
/* F5538 802D0B88 8C450000 */   lw       $a1, ($v0)
/* F553C 802D0B8C 0040202D */  daddu     $a0, $v0, $zero
/* F5540 802D0B90 26050074 */  addiu     $a1, $s0, 0x74
/* F5544 802D0B94 0C049640 */  jal       load_string
/* F5548 802D0B98 AE000074 */   sw       $zero, 0x74($s0)
/* F554C 802D0B9C 3C01802E */  lui       $at, 0x802e
/* F5550 802D0BA0 AC22B268 */  sw        $v0, -0x4d98($at)
.L802D0BA4:
/* F5554 802D0BA4 3C04802E */  lui       $a0, 0x802e
/* F5558 802D0BA8 2484B268 */  addiu     $a0, $a0, -0x4d98
/* F555C 802D0BAC 8C820000 */  lw        $v0, ($a0)
/* F5560 802D0BB0 3C03802E */  lui       $v1, 0x802e
/* F5564 802D0BB4 8C63B260 */  lw        $v1, -0x4da0($v1)
/* F5568 802D0BB8 904204E8 */  lbu       $v0, 0x4e8($v0)
/* F556C 802D0BBC A06204E8 */  sb        $v0, 0x4e8($v1)
/* F5570 802D0BC0 8C830000 */  lw        $v1, ($a0)
/* F5574 802D0BC4 304200FF */  andi      $v0, $v0, 0xff
/* F5578 802D0BC8 AE020084 */  sw        $v0, 0x84($s0)
/* F557C 802D0BCC 8C6204FC */  lw        $v0, 0x4fc($v1)
/* F5580 802D0BD0 30420040 */  andi      $v0, $v0, 0x40
/* F5584 802D0BD4 54400004 */  bnel      $v0, $zero, .L802D0BE8
/* F5588 802D0BD8 24020001 */   addiu    $v0, $zero, 1
/* F558C 802D0BDC 8E020074 */  lw        $v0, 0x74($s0)
/* F5590 802D0BE0 38420001 */  xori      $v0, $v0, 1
/* F5594 802D0BE4 2C420001 */  sltiu     $v0, $v0, 1
.L802D0BE8:
/* F5598 802D0BE8 8FBF0014 */  lw        $ra, 0x14($sp)
/* F559C 802D0BEC 8FB00010 */  lw        $s0, 0x10($sp)
/* F55A0 802D0BF0 03E00008 */  jr        $ra
/* F55A4 802D0BF4 27BD0018 */   addiu    $sp, $sp, 0x18
