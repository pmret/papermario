.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_801503B8
.word L80124600_BAD00, L80124664_BAD64, L801246C4_BADC4, L801246EC_BADEC, L801246EC_BADEC, L801246EC_BADEC, L801246EC_BADEC, L80124704_BAE04, L8012470C_BAE0C, L80124714_BAE14, L8012471C_BAE1C, L80124730_BAE30, L801247CC_BAECC, L80124B08_BB208, L801255A4_BBCA4, L80124B7C_BB27C

glabel jtbl_801503F8
.word L80124818_BAF18, L80124818_BAF18, L80124818_BAF18, L80124818_BAF18, L80124878_BAF78, L801248BC_BAFBC, L80124990_BB090, L80124984_BB084, L801249B8_BB0B8, L80124AA4_BB1A4, L80124AA4_BB1A4, L80124920_BB020, L801248BC_BAFBC, L80124AE8_BB1E8, L801248BC_BAFBC, 0

glabel jtbl_80150438
.word L80124BA4_BB2A4, L80124BC4_BB2C4, L80125600_BBD00, L80125138_BB838, L80125148_BB848, L80124BE8_BB2E8, L80124BF8_BB2F8, L80124C04_BB304, L80124C18_BB318, L80124C38_BB338, L80124C48_BB348, L80124C28_BB328, L80124C54_BB354, L80124CE8_BB3E8, L80124D54_BB454, L80124D78_BB478, L80124D94_BB494, L80124DB4_BB4B4, L80124DC4_BB4C4, L80124DD4_BB4D4, L80124DE4_BB4E4, L80124DF4_BB4F4, L80124E28_BB528, L80124E7C_BB57C, L80124F18_BB618, L80124FA8_BB6A8, L80124FCC_BB6CC, L80125020_BB720, L80125040_BB740, L80125084_BB784, L801250C4_BB7C4, L801250D4_BB7D4, L80125118_BB818, L80125128_BB828, L80125184_BB884, L80125194_BB894, L801251A4_BB8A4, L801251B4_BB8B4, L801251C4_BB8C4, L80125218_BB918, L80125244_BB944, L8012553C_BBC3C, L80125564_BBC64, L80125594_BBC94, L801254C0_BBBC0, L80125600_BBD00, L801254B0_BBBB0, L8012546C_BBB6C

glabel jtbl_801504F8
.word L80125204_BB904, L80125204_BB904, L80125204_BB904, L80125210_BB910, L80125600_BBD00, L80125210_BB910, L80125204_BB904, L80125210_BB910, L80125204_BB904, L80125204_BB904, L80125204_BB904, L80125204_BB904, L80125204_BB904, L80125204_BB904, L80125204_BB904, 0

glabel D_80150538
.word 0x801252CC, 0x801253D4, 0x801253D4, 0x80125300, 0x80125300, 0x80125300, 0x80125300, 0x80125314, 0x801253D4, 0x801253D4, 0x801253D4, 0x801253D4, 0x801253D4, 0x801253D4, 0x801253D4, 0x80125320

.section .text

glabel msg_copy_to_print_buffer
/* BAC70 80124570 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BAC74 80124574 AFB40030 */  sw        $s4, 0x30($sp)
/* BAC78 80124578 0080A02D */  daddu     $s4, $a0, $zero
/* BAC7C 8012457C AFB50034 */  sw        $s5, 0x34($sp)
/* BAC80 80124580 00A0A82D */  daddu     $s5, $a1, $zero
/* BAC84 80124584 26880468 */  addiu     $t0, $s4, 0x468
/* BAC88 80124588 AFB7003C */  sw        $s7, 0x3c($sp)
/* BAC8C 8012458C 24170002 */  addiu     $s7, $zero, 2
/* BAC90 80124590 AFBE0040 */  sw        $fp, 0x40($sp)
/* BAC94 80124594 30DE0001 */  andi      $fp, $a2, 1
/* BAC98 80124598 AFB60038 */  sw        $s6, 0x38($sp)
/* BAC9C 8012459C 241600FF */  addiu     $s6, $zero, 0xff
/* BACA0 801245A0 AFBF0044 */  sw        $ra, 0x44($sp)
/* BACA4 801245A4 AFB3002C */  sw        $s3, 0x2c($sp)
/* BACA8 801245A8 AFB20028 */  sw        $s2, 0x28($sp)
/* BACAC 801245AC AFB10024 */  sw        $s1, 0x24($sp)
/* BACB0 801245B0 AFB00020 */  sw        $s0, 0x20($sp)
/* BACB4 801245B4 AFA80018 */  sw        $t0, 0x18($sp)
/* BACB8 801245B8 96820004 */  lhu       $v0, 4($s4)
/* BACBC 801245BC 9684000C */  lhu       $a0, 0xc($s4)
/* BACC0 801245C0 8E830000 */  lw        $v1, ($s4)
/* BACC4 801245C4 24420010 */  addiu     $v0, $v0, 0x10
/* BACC8 801245C8 02829021 */  addu      $s2, $s4, $v0
/* BACCC 801245CC 00649821 */  addu      $s3, $v1, $a0
.L801245D0:
/* BACD0 801245D0 92650000 */  lbu       $a1, ($s3)
/* BACD4 801245D4 26730001 */  addiu     $s3, $s3, 1
/* BACD8 801245D8 92660000 */  lbu       $a2, ($s3)
/* BACDC 801245DC 24A3FF10 */  addiu     $v1, $a1, -0xf0
/* BACE0 801245E0 2C620010 */  sltiu     $v0, $v1, 0x10
/* BACE4 801245E4 104003EF */  beqz      $v0, L801255A4_BBCA4
/* BACE8 801245E8 00031080 */   sll      $v0, $v1, 2
/* BACEC 801245EC 3C018015 */  lui       $at, %hi(jtbl_801503B8)
/* BACF0 801245F0 00220821 */  addu      $at, $at, $v0
/* BACF4 801245F4 8C2203B8 */  lw        $v0, %lo(jtbl_801503B8)($at)
/* BACF8 801245F8 00400008 */  jr        $v0
/* BACFC 801245FC 00000000 */   nop
glabel L80124600_BAD00
/* BAD00 80124600 240200F0 */  addiu     $v0, $zero, 0xf0
/* BAD04 80124604 A2420000 */  sb        $v0, ($s2)
/* BAD08 80124608 C6800540 */  lwc1      $f0, 0x540($s4)
/* BAD0C 8012460C 3C014F00 */  lui       $at, 0x4f00
/* BAD10 80124610 44811000 */  mtc1      $at, $f2
/* BAD14 80124614 00000000 */  nop
/* BAD18 80124618 4600103E */  c.le.s    $f2, $f0
/* BAD1C 8012461C 00000000 */  nop
/* BAD20 80124620 45010005 */  bc1t      .L80124638
/* BAD24 80124624 26520001 */   addiu    $s2, $s2, 1
/* BAD28 80124628 4600010D */  trunc.w.s $f4, $f0
/* BAD2C 8012462C 44032000 */  mfc1      $v1, $f4
/* BAD30 80124630 08049194 */  j         .L80124650
/* BAD34 80124634 00000000 */   nop
.L80124638:
/* BAD38 80124638 46020001 */  sub.s     $f0, $f0, $f2
/* BAD3C 8012463C 3C028000 */  lui       $v0, 0x8000
/* BAD40 80124640 4600010D */  trunc.w.s $f4, $f0
/* BAD44 80124644 44032000 */  mfc1      $v1, $f4
/* BAD48 80124648 00000000 */  nop
/* BAD4C 8012464C 00621825 */  or        $v1, $v1, $v0
.L80124650:
/* BAD50 80124650 8FA80018 */  lw        $t0, 0x18($sp)
/* BAD54 80124654 91020000 */  lbu       $v0, ($t0)
/* BAD58 80124658 00431021 */  addu      $v0, $v0, $v1
/* BAD5C 8012465C 08049580 */  j         L80125600_BBD00
/* BAD60 80124660 A1020000 */   sb       $v0, ($t0)
glabel L80124664_BAD64
/* BAD64 80124664 96830500 */  lhu       $v1, 0x500($s4)
/* BAD68 80124668 24020005 */  addiu     $v0, $zero, 5
/* BAD6C 8012466C A28204F8 */  sb        $v0, 0x4f8($s4)
/* BAD70 80124670 34630001 */  ori       $v1, $v1, 1
/* BAD74 80124674 3063FFFD */  andi      $v1, $v1, 0xfffd
/* BAD78 80124678 A6830500 */  sh        $v1, 0x500($s4)
/* BAD7C 8012467C 8E8304FC */  lw        $v1, 0x4fc($s4)
/* BAD80 80124680 2402FF7F */  addiu     $v0, $zero, -0x81
/* BAD84 80124684 A280047C */  sb        $zero, 0x47c($s4)
/* BAD88 80124688 A680047E */  sh        $zero, 0x47e($s4)
/* BAD8C 8012468C 00621824 */  and       $v1, $v1, $v0
/* BAD90 80124690 2402FEFF */  addiu     $v0, $zero, -0x101
/* BAD94 80124694 00621824 */  and       $v1, $v1, $v0
/* BAD98 80124698 AE8304FC */  sw        $v1, 0x4fc($s4)
/* BAD9C 8012469C 92830508 */  lbu       $v1, 0x508($s4)
/* BADA0 801246A0 2402000F */  addiu     $v0, $zero, 0xf
/* BADA4 801246A4 106203D6 */  beq       $v1, $v0, L80125600_BBD00
/* BADA8 801246A8 240400CB */   addiu    $a0, $zero, 0xcb
/* BADAC 801246AC 0000282D */  daddu     $a1, $zero, $zero
/* BADB0 801246B0 00A0302D */  daddu     $a2, $a1, $zero
/* BADB4 801246B4 0C0526AE */  jal       sfx_play_sound_with_params
/* BADB8 801246B8 00A0382D */   daddu    $a3, $a1, $zero
/* BADBC 801246BC 08049580 */  j         L80125600_BBD00
/* BADC0 801246C0 00000000 */   nop
glabel L801246C4_BADC4
/* BADC4 801246C4 96820500 */  lhu       $v0, 0x500($s4)
/* BADC8 801246C8 92630000 */  lbu       $v1, ($s3)
/* BADCC 801246CC 34420001 */  ori       $v0, $v0, 1
/* BADD0 801246D0 A6820500 */  sh        $v0, 0x500($s4)
/* BADD4 801246D4 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BADD8 801246D8 26730001 */  addiu     $s3, $s3, 1
/* BADDC 801246DC A683000E */  sh        $v1, 0xe($s4)
/* BADE0 801246E0 2403FF7F */  addiu     $v1, $zero, -0x81
/* BADE4 801246E4 0804957F */  j         .L801255FC
/* BADE8 801246E8 00431024 */   and      $v0, $v0, $v1
glabel L801246EC_BADEC
/* BADEC 801246EC 24A200FE */  addiu     $v0, $a1, 0xfe
/* BADF0 801246F0 A2420000 */  sb        $v0, ($s2)
/* BADF4 801246F4 26520001 */  addiu     $s2, $s2, 1
/* BADF8 801246F8 24A2000D */  addiu     $v0, $a1, 0xd
/* BADFC 801246FC 08049580 */  j         L80125600_BBD00
/* BAE00 80124700 A2820455 */   sb       $v0, 0x455($s4)
glabel L80124704_BAE04
/* BAE04 80124704 08049556 */  j         .L80125558
/* BAE08 80124708 240200F5 */   addiu    $v0, $zero, 0xf5
glabel L8012470C_BAE0C
/* BAE0C 8012470C 08049556 */  j         .L80125558
/* BAE10 80124710 240200F6 */   addiu    $v0, $zero, 0xf6
glabel L80124714_BAE14
/* BAE14 80124714 08049556 */  j         .L80125558
/* BAE18 80124718 240200F7 */   addiu    $v0, $zero, 0xf7
glabel L8012471C_BAE1C
/* BAE1C 8012471C 240200F9 */  addiu     $v0, $zero, 0xf9
/* BAE20 80124720 A2420000 */  sb        $v0, ($s2)
/* BAE24 80124724 26520001 */  addiu     $s2, $s2, 1
/* BAE28 80124728 08049580 */  j         L80125600_BBD00
/* BAE2C 8012472C 26B5FFFF */   addiu    $s5, $s5, -1
glabel L80124730_BAE30
/* BAE30 80124730 92820468 */  lbu       $v0, 0x468($s4)
/* BAE34 80124734 504003B2 */  beql      $v0, $zero, L80125600_BBD00
/* BAE38 80124738 A2800468 */   sb       $zero, 0x468($s4)
/* BAE3C 8012473C 92820486 */  lbu       $v0, 0x486($s4)
/* BAE40 80124740 96830462 */  lhu       $v1, 0x462($s4)
/* BAE44 80124744 00021040 */  sll       $v0, $v0, 1
/* BAE48 80124748 02821021 */  addu      $v0, $s4, $v0
/* BAE4C 8012474C A4430488 */  sh        $v1, 0x488($v0)
/* BAE50 80124750 92820486 */  lbu       $v0, 0x486($s4)
/* BAE54 80124754 24420001 */  addiu     $v0, $v0, 1
/* BAE58 80124758 A2820486 */  sb        $v0, 0x486($s4)
/* BAE5C 8012475C 240200FA */  addiu     $v0, $zero, 0xfa
/* BAE60 80124760 A2420000 */  sb        $v0, ($s2)
/* BAE64 80124764 26520001 */  addiu     $s2, $s2, 1
/* BAE68 80124768 92820454 */  lbu       $v0, 0x454($s4)
/* BAE6C 8012476C 92830508 */  lbu       $v1, 0x508($s4)
/* BAE70 80124770 00021080 */  sll       $v0, $v0, 2
/* BAE74 80124774 00031840 */  sll       $v1, $v1, 1
/* BAE78 80124778 3C01802F */  lui       $at, %hi(gMsgCharsets)
/* BAE7C 8012477C 00220821 */  addu      $at, $at, $v0
/* BAE80 80124780 8C22B5A8 */  lw        $v0, %lo(gMsgCharsets)($at)
/* BAE84 80124784 3C01802F */  lui       $at, %hi(D_802EB644)
/* BAE88 80124788 00230821 */  addu      $at, $at, $v1
/* BAE8C 8012478C 8423B644 */  lh        $v1, %lo(D_802EB644)($at)
/* BAE90 80124790 90440003 */  lbu       $a0, 3($v0)
/* BAE94 80124794 24020006 */  addiu     $v0, $zero, 6
/* BAE98 80124798 A28204F8 */  sb        $v0, 0x4f8($s4)
/* BAE9C 8012479C 92820468 */  lbu       $v0, 0x468($s4)
/* BAEA0 801247A0 00832021 */  addu      $a0, $a0, $v1
/* BAEA4 801247A4 00820018 */  mult      $a0, $v0
/* BAEA8 801247A8 96820500 */  lhu       $v0, 0x500($s4)
/* BAEAC 801247AC 96830462 */  lhu       $v1, 0x462($s4)
/* BAEB0 801247B0 34420001 */  ori       $v0, $v0, 1
/* BAEB4 801247B4 A6820500 */  sh        $v0, 0x500($s4)
/* BAEB8 801247B8 00004012 */  mflo      $t0
/* BAEBC 801247BC 00681821 */  addu      $v1, $v1, $t0
/* BAEC0 801247C0 A6830466 */  sh        $v1, 0x466($s4)
/* BAEC4 801247C4 08049580 */  j         L80125600_BBD00
/* BAEC8 801247C8 A2800468 */   sb       $zero, 0x468($s4)
glabel L801247CC_BAECC
/* BAECC 801247CC 240200F8 */  addiu     $v0, $zero, 0xf8
/* BAED0 801247D0 A2420000 */  sb        $v0, ($s2)
/* BAED4 801247D4 26520001 */  addiu     $s2, $s2, 1
/* BAED8 801247D8 92700000 */  lbu       $s0, ($s3)
/* BAEDC 801247DC 26730001 */  addiu     $s3, $s3, 1
/* BAEE0 801247E0 A2900508 */  sb        $s0, 0x508($s4)
/* BAEE4 801247E4 A2500000 */  sb        $s0, ($s2)
/* BAEE8 801247E8 26520001 */  addiu     $s2, $s2, 1
/* BAEEC 801247EC 320200FF */  andi      $v0, $s0, 0xff
/* BAEF0 801247F0 2443FFFF */  addiu     $v1, $v0, -1
/* BAEF4 801247F4 2C62000F */  sltiu     $v0, $v1, 0xf
/* BAEF8 801247F8 104000BD */  beqz      $v0, .L80124AF0
/* BAEFC 801247FC A2800509 */   sb       $zero, 0x509($s4)
/* BAF00 80124800 00031080 */  sll       $v0, $v1, 2
/* BAF04 80124804 3C018015 */  lui       $at, %hi(jtbl_801503F8)
/* BAF08 80124808 00220821 */  addu      $at, $at, $v0
/* BAF0C 8012480C 8C2203F8 */  lw        $v0, %lo(jtbl_801503F8)($at)
/* BAF10 80124810 00400008 */  jr        $v0
/* BAF14 80124814 00000000 */   nop
glabel L80124818_BAF18
/* BAF18 80124818 2602FFFF */  addiu     $v0, $s0, -1
/* BAF1C 8012481C 2C420003 */  sltiu     $v0, $v0, 3
/* BAF20 80124820 10400002 */  beqz      $v0, .L8012482C
/* BAF24 80124824 24020003 */   addiu    $v0, $zero, 3
/* BAF28 80124828 A282053C */  sb        $v0, 0x53c($s4)
.L8012482C:
/* BAF2C 8012482C 3C040080 */  lui       $a0, 0x80
/* BAF30 80124830 34840800 */  ori       $a0, $a0, 0x800
/* BAF34 80124834 96820500 */  lhu       $v0, 0x500($s4)
/* BAF38 80124838 8E8304FC */  lw        $v1, 0x4fc($s4)
/* BAF3C 8012483C 34420001 */  ori       $v0, $v0, 1
/* BAF40 80124840 00642025 */  or        $a0, $v1, $a0
/* BAF44 80124844 30C300FF */  andi      $v1, $a2, 0xff
/* BAF48 80124848 A6820500 */  sh        $v0, 0x500($s4)
/* BAF4C 8012484C 240200C3 */  addiu     $v0, $zero, 0xc3
/* BAF50 80124850 10620003 */  beq       $v1, $v0, .L80124860
/* BAF54 80124854 AE8404FC */   sw       $a0, 0x4fc($s4)
/* BAF58 80124858 34820080 */  ori       $v0, $a0, 0x80
/* BAF5C 8012485C AE8204FC */  sw        $v0, 0x4fc($s4)
.L80124860:
/* BAF60 80124860 24020011 */  addiu     $v0, $zero, 0x11
/* BAF64 80124864 AE820520 */  sw        $v0, 0x520($s4)
/* BAF68 80124868 24020012 */  addiu     $v0, $zero, 0x12
/* BAF6C 8012486C AE820524 */  sw        $v0, 0x524($s4)
/* BAF70 80124870 080492BC */  j         .L80124AF0
/* BAF74 80124874 A29704F8 */   sb       $s7, 0x4f8($s4)
glabel L80124878_BAF78
/* BAF78 80124878 92620000 */  lbu       $v0, ($s3)
/* BAF7C 8012487C 26730001 */  addiu     $s3, $s3, 1
/* BAF80 80124880 A682045A */  sh        $v0, 0x45a($s4)
/* BAF84 80124884 92620000 */  lbu       $v0, ($s3)
/* BAF88 80124888 26730001 */  addiu     $s3, $s3, 1
/* BAF8C 8012488C A682045C */  sh        $v0, 0x45c($s4)
/* BAF90 80124890 92620000 */  lbu       $v0, ($s3)
/* BAF94 80124894 26730001 */  addiu     $s3, $s3, 1
/* BAF98 80124898 A6820514 */  sh        $v0, 0x514($s4)
/* BAF9C 8012489C 92630000 */  lbu       $v1, ($s3)
/* BAFA0 801248A0 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BAFA4 801248A4 26730001 */  addiu     $s3, $s3, 1
/* BAFA8 801248A8 A29704F8 */  sb        $s7, 0x4f8($s4)
/* BAFAC 801248AC 34420800 */  ori       $v0, $v0, 0x800
/* BAFB0 801248B0 AE8204FC */  sw        $v0, 0x4fc($s4)
/* BAFB4 801248B4 080492BC */  j         .L80124AF0
/* BAFB8 801248B8 A6830516 */   sh       $v1, 0x516($s4)
glabel L801248BC_BAFBC
/* BAFBC 801248BC 17C0008C */  bnez      $fp, .L80124AF0
/* BAFC0 801248C0 24020014 */   addiu    $v0, $zero, 0x14
/* BAFC4 801248C4 A682045A */  sh        $v0, 0x45a($s4)
/* BAFC8 801248C8 2402001C */  addiu     $v0, $zero, 0x1c
/* BAFCC 801248CC A682045C */  sh        $v0, 0x45c($s4)
/* BAFD0 801248D0 2402003A */  addiu     $v0, $zero, 0x3a
/* BAFD4 801248D4 A6820516 */  sh        $v0, 0x516($s4)
/* BAFD8 801248D8 24020118 */  addiu     $v0, $zero, 0x118
/* BAFDC 801248DC A6820514 */  sh        $v0, 0x514($s4)
/* BAFE0 801248E0 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BAFE4 801248E4 96830500 */  lhu       $v1, 0x500($s4)
/* BAFE8 801248E8 A29704F8 */  sb        $s7, 0x4f8($s4)
/* BAFEC 801248EC 34420800 */  ori       $v0, $v0, 0x800
/* BAFF0 801248F0 34630001 */  ori       $v1, $v1, 1
/* BAFF4 801248F4 AE8204FC */  sw        $v0, 0x4fc($s4)
/* BAFF8 801248F8 24020006 */  addiu     $v0, $zero, 6
/* BAFFC 801248FC 1602007C */  bne       $s0, $v0, .L80124AF0
/* BB000 80124900 A6830500 */   sh       $v1, 0x500($s4)
/* BB004 80124904 2404021C */  addiu     $a0, $zero, 0x21c
/* BB008 80124908 0000282D */  daddu     $a1, $zero, $zero
/* BB00C 8012490C 00A0302D */  daddu     $a2, $a1, $zero
/* BB010 80124910 0C0526AE */  jal       sfx_play_sound_with_params
/* BB014 80124914 00A0382D */   daddu    $a3, $a1, $zero
/* BB018 80124918 080492BC */  j         .L80124AF0
/* BB01C 8012491C 00000000 */   nop
glabel L80124920_BB020
/* BB020 80124920 92620000 */  lbu       $v0, ($s3)
/* BB024 80124924 26730001 */  addiu     $s3, $s3, 1
/* BB028 80124928 2404021C */  addiu     $a0, $zero, 0x21c
/* BB02C 8012492C 0000282D */  daddu     $a1, $zero, $zero
/* BB030 80124930 00A0302D */  daddu     $a2, $a1, $zero
/* BB034 80124934 A682045A */  sh        $v0, 0x45a($s4)
/* BB038 80124938 92620000 */  lbu       $v0, ($s3)
/* BB03C 8012493C 26730001 */  addiu     $s3, $s3, 1
/* BB040 80124940 A682045C */  sh        $v0, 0x45c($s4)
/* BB044 80124944 92620000 */  lbu       $v0, ($s3)
/* BB048 80124948 26730001 */  addiu     $s3, $s3, 1
/* BB04C 8012494C A6820514 */  sh        $v0, 0x514($s4)
/* BB050 80124950 92620000 */  lbu       $v0, ($s3)
/* BB054 80124954 00A0382D */  daddu     $a3, $a1, $zero
/* BB058 80124958 0C0526AE */  jal       sfx_play_sound_with_params
/* BB05C 8012495C A6820516 */   sh       $v0, 0x516($s4)
/* BB060 80124960 96820500 */  lhu       $v0, 0x500($s4)
/* BB064 80124964 8E8304FC */  lw        $v1, 0x4fc($s4)
/* BB068 80124968 26730001 */  addiu     $s3, $s3, 1
/* BB06C 8012496C A29704F8 */  sb        $s7, 0x4f8($s4)
/* BB070 80124970 34420001 */  ori       $v0, $v0, 1
/* BB074 80124974 34630800 */  ori       $v1, $v1, 0x800
/* BB078 80124978 A6820500 */  sh        $v0, 0x500($s4)
/* BB07C 8012497C 080492BC */  j         .L80124AF0
/* BB080 80124980 AE8304FC */   sw       $v1, 0x4fc($s4)
glabel L80124984_BB084
/* BB084 80124984 92620000 */  lbu       $v0, ($s3)
/* BB088 80124988 26730001 */  addiu     $s3, $s3, 1
/* BB08C 8012498C A6820516 */  sh        $v0, 0x516($s4)
glabel L80124990_BB090
/* BB090 80124990 17C00057 */  bnez      $fp, .L80124AF0
/* BB094 80124994 00000000 */   nop
/* BB098 80124998 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BB09C 8012499C 96830500 */  lhu       $v1, 0x500($s4)
/* BB0A0 801249A0 A29704F8 */  sb        $s7, 0x4f8($s4)
/* BB0A4 801249A4 34420800 */  ori       $v0, $v0, 0x800
/* BB0A8 801249A8 34630001 */  ori       $v1, $v1, 1
/* BB0AC 801249AC AE8204FC */  sw        $v0, 0x4fc($s4)
/* BB0B0 801249B0 080492BC */  j         .L80124AF0
/* BB0B4 801249B4 A6830500 */   sh       $v1, 0x500($s4)
glabel L801249B8_BB0B8
/* BB0B8 801249B8 92700000 */  lbu       $s0, ($s3)
/* BB0BC 801249BC 26730001 */  addiu     $s3, $s3, 1
/* BB0C0 801249C0 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BB0C4 801249C4 96830500 */  lhu       $v1, 0x500($s4)
/* BB0C8 801249C8 24041EC3 */  addiu     $a0, $zero, 0x1ec3
/* BB0CC 801249CC A29704F8 */  sb        $s7, 0x4f8($s4)
/* BB0D0 801249D0 34420800 */  ori       $v0, $v0, 0x800
/* BB0D4 801249D4 34630001 */  ori       $v1, $v1, 1
/* BB0D8 801249D8 AE8204FC */  sw        $v0, 0x4fc($s4)
/* BB0DC 801249DC 0C00AB39 */  jal       heap_malloc
/* BB0E0 801249E0 A6830500 */   sh       $v1, 0x500($s4)
/* BB0E4 801249E4 3C030001 */  lui       $v1, 1
/* BB0E8 801249E8 2463B290 */  addiu     $v1, $v1, -0x4d70
/* BB0EC 801249EC 3C080011 */  lui       $t0, 0x11
/* BB0F0 801249F0 2508F1B0 */  addiu     $t0, $t0, -0xe50
/* BB0F4 801249F4 01032021 */  addu      $a0, $t0, $v1
/* BB0F8 801249F8 24851EC3 */  addiu     $a1, $a0, 0x1ec3
/* BB0FC 801249FC 0040302D */  daddu     $a2, $v0, $zero
/* BB100 80124A00 0C00A5CF */  jal       dma_copy
/* BB104 80124A04 AE860544 */   sw       $a2, 0x544($s4)
/* BB108 80124A08 0C00AB39 */  jal       heap_malloc
/* BB10C 80124A0C 24040020 */   addiu    $a0, $zero, 0x20
/* BB110 80124A10 3C030001 */  lui       $v1, 1
/* BB114 80124A14 2463D158 */  addiu     $v1, $v1, -0x2ea8
/* BB118 80124A18 3C080011 */  lui       $t0, 0x11
/* BB11C 80124A1C 2508F1B0 */  addiu     $t0, $t0, -0xe50
/* BB120 80124A20 01032021 */  addu      $a0, $t0, $v1
/* BB124 80124A24 24850020 */  addiu     $a1, $a0, 0x20
/* BB128 80124A28 0040302D */  daddu     $a2, $v0, $zero
/* BB12C 80124A2C 0C00A5CF */  jal       dma_copy
/* BB130 80124A30 AE860548 */   sw       $a2, 0x548($s4)
/* BB134 80124A34 0C00AB39 */  jal       heap_malloc
/* BB138 80124A38 240419FA */   addiu    $a0, $zero, 0x19fa
/* BB13C 80124A3C 321000FF */  andi      $s0, $s0, 0xff
/* BB140 80124A40 00108080 */  sll       $s0, $s0, 2
/* BB144 80124A44 0040302D */  daddu     $a2, $v0, $zero
/* BB148 80124A48 AE82054C */  sw        $v0, 0x54c($s4)
/* BB14C 80124A4C 3C03802F */  lui       $v1, %hi(D_802EB5C0)
/* BB150 80124A50 00701821 */  addu      $v1, $v1, $s0
/* BB154 80124A54 8C63B5C0 */  lw        $v1, %lo(D_802EB5C0)($v1)
/* BB158 80124A58 3C080011 */  lui       $t0, 0x11
/* BB15C 80124A5C 2508F1B0 */  addiu     $t0, $t0, -0xe50
/* BB160 80124A60 00682021 */  addu      $a0, $v1, $t0
/* BB164 80124A64 0C00A5CF */  jal       dma_copy
/* BB168 80124A68 248519FA */   addiu    $a1, $a0, 0x19fa
/* BB16C 80124A6C 0C00AB39 */  jal       heap_malloc
/* BB170 80124A70 24040200 */   addiu    $a0, $zero, 0x200
/* BB174 80124A74 0040302D */  daddu     $a2, $v0, $zero
/* BB178 80124A78 AE820550 */  sw        $v0, 0x550($s4)
/* BB17C 80124A7C 3C03802F */  lui       $v1, %hi(D_802EB5F0)
/* BB180 80124A80 00701821 */  addu      $v1, $v1, $s0
/* BB184 80124A84 8C63B5F0 */  lw        $v1, %lo(D_802EB5F0)($v1)
/* BB188 80124A88 3C080011 */  lui       $t0, 0x11
/* BB18C 80124A8C 2508F1B0 */  addiu     $t0, $t0, -0xe50
/* BB190 80124A90 00682021 */  addu      $a0, $v1, $t0
/* BB194 80124A94 0C00A5CF */  jal       dma_copy
/* BB198 80124A98 24850200 */   addiu    $a1, $a0, 0x200
/* BB19C 80124A9C 080492BC */  j         .L80124AF0
/* BB1A0 80124AA0 00000000 */   nop
glabel L80124AA4_BB1A4
/* BB1A4 80124AA4 24020028 */  addiu     $v0, $zero, 0x28
/* BB1A8 80124AA8 A6820516 */  sh        $v0, 0x516($s4)
/* BB1AC 80124AAC 96820538 */  lhu       $v0, 0x538($s4)
/* BB1B0 80124AB0 8E8304FC */  lw        $v1, 0x4fc($s4)
/* BB1B4 80124AB4 24420020 */  addiu     $v0, $v0, 0x20
/* BB1B8 80124AB8 A6820514 */  sh        $v0, 0x514($s4)
/* BB1BC 80124ABC 34628000 */  ori       $v0, $v1, 0x8000
/* BB1C0 80124AC0 17C0000B */  bnez      $fp, .L80124AF0
/* BB1C4 80124AC4 AE8204FC */   sw       $v0, 0x4fc($s4)
/* BB1C8 80124AC8 34628800 */  ori       $v0, $v1, 0x8800
/* BB1CC 80124ACC 96830500 */  lhu       $v1, 0x500($s4)
/* BB1D0 80124AD0 AE8204FC */  sw        $v0, 0x4fc($s4)
/* BB1D4 80124AD4 2402000D */  addiu     $v0, $zero, 0xd
/* BB1D8 80124AD8 A28204F8 */  sb        $v0, 0x4f8($s4)
/* BB1DC 80124ADC 34630001 */  ori       $v1, $v1, 1
/* BB1E0 80124AE0 080492BC */  j         .L80124AF0
/* BB1E4 80124AE4 A6830500 */   sh       $v1, 0x500($s4)
glabel L80124AE8_BB1E8
/* BB1E8 80124AE8 24020004 */  addiu     $v0, $zero, 4
/* BB1EC 80124AEC A28204F8 */  sb        $v0, 0x4f8($s4)
.L80124AF0:
/* BB1F0 80124AF0 96830500 */  lhu       $v1, 0x500($s4)
/* BB1F4 80124AF4 30620001 */  andi      $v0, $v1, 1
/* BB1F8 80124AF8 104002C1 */  beqz      $v0, L80125600_BBD00
/* BB1FC 80124AFC 30620006 */   andi     $v0, $v1, 6
/* BB200 80124B00 080493E6 */  j         .L80124F98
/* BB204 80124B04 00000000 */   nop
glabel L80124B08_BB208
/* BB208 80124B08 240200FB */  addiu     $v0, $zero, 0xfb
/* BB20C 80124B0C A2420000 */  sb        $v0, ($s2)
/* BB210 80124B10 8E8304FC */  lw        $v1, 0x4fc($s4)
/* BB214 80124B14 30620800 */  andi      $v0, $v1, 0x800
/* BB218 80124B18 10400011 */  beqz      $v0, .L80124B60
/* BB21C 80124B1C 26520001 */   addiu    $s2, $s2, 1
/* BB220 80124B20 30621000 */  andi      $v0, $v1, 0x1000
/* BB224 80124B24 10400005 */  beqz      $v0, .L80124B3C
/* BB228 80124B28 00000000 */   nop
/* BB22C 80124B2C 8E830504 */  lw        $v1, 0x504($s4)
/* BB230 80124B30 10600002 */  beqz      $v1, .L80124B3C
/* BB234 80124B34 24020001 */   addiu    $v0, $zero, 1
/* BB238 80124B38 AC620000 */  sw        $v0, ($v1)
.L80124B3C:
/* BB23C 80124B3C 92820508 */  lbu       $v0, 0x508($s4)
/* BB240 80124B40 2442FFF6 */  addiu     $v0, $v0, -0xa
/* BB244 80124B44 2C420002 */  sltiu     $v0, $v0, 2
/* BB248 80124B48 14400002 */  bnez      $v0, .L80124B54
/* BB24C 80124B4C 2402000E */   addiu    $v0, $zero, 0xe
/* BB250 80124B50 24020003 */  addiu     $v0, $zero, 3
.L80124B54:
/* BB254 80124B54 A28204F8 */  sb        $v0, 0x4f8($s4)
/* BB258 80124B58 080492DA */  j         .L80124B68
/* BB25C 80124B5C A2800512 */   sb       $zero, 0x512($s4)
.L80124B60:
/* BB260 80124B60 34620001 */  ori       $v0, $v1, 1
/* BB264 80124B64 AE8204FC */  sw        $v0, 0x4fc($s4)
.L80124B68:
/* BB268 80124B68 96820500 */  lhu       $v0, 0x500($s4)
/* BB26C 80124B6C 34420001 */  ori       $v0, $v0, 1
/* BB270 80124B70 3042FFFD */  andi      $v0, $v0, 0xfffd
/* BB274 80124B74 08049580 */  j         L80125600_BBD00
/* BB278 80124B78 A6820500 */   sh       $v0, 0x500($s4)
glabel L80124B7C_BB27C
/* BB27C 80124B7C 92630000 */  lbu       $v1, ($s3)
/* BB280 80124B80 2C620030 */  sltiu     $v0, $v1, 0x30
/* BB284 80124B84 1040029E */  beqz      $v0, L80125600_BBD00
/* BB288 80124B88 26730001 */   addiu    $s3, $s3, 1
/* BB28C 80124B8C 00031080 */  sll       $v0, $v1, 2
/* BB290 80124B90 3C018015 */  lui       $at, %hi(jtbl_80150438)
/* BB294 80124B94 00220821 */  addu      $at, $at, $v0
/* BB298 80124B98 8C220438 */  lw        $v0, %lo(jtbl_80150438)($at)
/* BB29C 80124B9C 00400008 */  jr        $v0
/* BB2A0 80124BA0 00000000 */   nop
glabel L80124BA4_BB2A4
/* BB2A4 80124BA4 A2560000 */  sb        $s6, ($s2)
/* BB2A8 80124BA8 26520001 */  addiu     $s2, $s2, 1
/* BB2AC 80124BAC A2400000 */  sb        $zero, ($s2)
/* BB2B0 80124BB0 26520001 */  addiu     $s2, $s2, 1
/* BB2B4 80124BB4 92620000 */  lbu       $v0, ($s3)
/* BB2B8 80124BB8 26730001 */  addiu     $s3, $s3, 1
/* BB2BC 80124BBC 08049556 */  j         .L80125558
/* BB2C0 80124BC0 A2820454 */   sb       $v0, 0x454($s4)
glabel L80124BC4_BB2C4
/* BB2C4 80124BC4 A2560000 */  sb        $s6, ($s2)
/* BB2C8 80124BC8 26520001 */  addiu     $s2, $s2, 1
/* BB2CC 80124BCC 24020001 */  addiu     $v0, $zero, 1
/* BB2D0 80124BD0 A2420000 */  sb        $v0, ($s2)
/* BB2D4 80124BD4 26520001 */  addiu     $s2, $s2, 1
/* BB2D8 80124BD8 92620000 */  lbu       $v0, ($s3)
/* BB2DC 80124BDC 26730001 */  addiu     $s3, $s3, 1
/* BB2E0 80124BE0 08049556 */  j         .L80125558
/* BB2E4 80124BE4 A2820455 */   sb       $v0, 0x455($s4)
glabel L80124BE8_BB2E8
/* BB2E8 80124BE8 A2560000 */  sb        $s6, ($s2)
/* BB2EC 80124BEC 26520001 */  addiu     $s2, $s2, 1
/* BB2F0 80124BF0 08049552 */  j         .L80125548
/* BB2F4 80124BF4 24020004 */   addiu    $v0, $zero, 4
glabel L80124BF8_BB2F8
/* BB2F8 80124BF8 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BB2FC 80124BFC 0804957F */  j         .L801255FC
/* BB300 80124C00 34420010 */   ori      $v0, $v0, 0x10
glabel L80124C04_BB304
/* BB304 80124C04 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BB308 80124C08 2403FEFF */  addiu     $v1, $zero, -0x101
/* BB30C 80124C0C 34420020 */  ori       $v0, $v0, 0x20
/* BB310 80124C10 0804957F */  j         .L801255FC
/* BB314 80124C14 00431024 */   and      $v0, $v0, $v1
glabel L80124C18_BB318
/* BB318 80124C18 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BB31C 80124C1C 2403FFDF */  addiu     $v1, $zero, -0x21
/* BB320 80124C20 0804957F */  j         .L801255FC
/* BB324 80124C24 00431024 */   and      $v0, $v0, $v1
glabel L80124C28_BB328
/* BB328 80124C28 A2560000 */  sb        $s6, ($s2)
/* BB32C 80124C2C 26520001 */  addiu     $s2, $s2, 1
/* BB330 80124C30 08049552 */  j         .L80125548
/* BB334 80124C34 24020005 */   addiu    $v0, $zero, 5
glabel L80124C38_BB338
/* BB338 80124C38 96820500 */  lhu       $v0, 0x500($s4)
/* BB33C 80124C3C 34420002 */  ori       $v0, $v0, 2
/* BB340 80124C40 08049580 */  j         L80125600_BBD00
/* BB344 80124C44 A6820500 */   sh       $v0, 0x500($s4)
glabel L80124C48_BB348
/* BB348 80124C48 96820500 */  lhu       $v0, 0x500($s4)
/* BB34C 80124C4C 0804941E */  j         .L80125078
/* BB350 80124C50 3042FFFD */   andi     $v0, $v0, 0xfffd
glabel L80124C54_BB354
/* BB354 80124C54 92820486 */  lbu       $v0, 0x486($s4)
/* BB358 80124C58 96830462 */  lhu       $v1, 0x462($s4)
/* BB35C 80124C5C 00021040 */  sll       $v0, $v0, 1
/* BB360 80124C60 02821021 */  addu      $v0, $s4, $v0
/* BB364 80124C64 A4430488 */  sh        $v1, 0x488($v0)
/* BB368 80124C68 92820486 */  lbu       $v0, 0x486($s4)
/* BB36C 80124C6C 24420001 */  addiu     $v0, $v0, 1
/* BB370 80124C70 A2820486 */  sb        $v0, 0x486($s4)
/* BB374 80124C74 240200FA */  addiu     $v0, $zero, 0xfa
/* BB378 80124C78 A2420000 */  sb        $v0, ($s2)
/* BB37C 80124C7C 26520001 */  addiu     $s2, $s2, 1
/* BB380 80124C80 92700000 */  lbu       $s0, ($s3)
/* BB384 80124C84 26730001 */  addiu     $s3, $s3, 1
/* BB388 80124C88 92820454 */  lbu       $v0, 0x454($s4)
/* BB38C 80124C8C 92830508 */  lbu       $v1, 0x508($s4)
/* BB390 80124C90 00021080 */  sll       $v0, $v0, 2
/* BB394 80124C94 00031840 */  sll       $v1, $v1, 1
/* BB398 80124C98 3C01802F */  lui       $at, %hi(gMsgCharsets)
/* BB39C 80124C9C 00220821 */  addu      $at, $at, $v0
/* BB3A0 80124CA0 8C22B5A8 */  lw        $v0, %lo(gMsgCharsets)($at)
/* BB3A4 80124CA4 3C01802F */  lui       $at, %hi(D_802EB644)
/* BB3A8 80124CA8 00230821 */  addu      $at, $at, $v1
/* BB3AC 80124CAC 8423B644 */  lh        $v1, %lo(D_802EB644)($at)
/* BB3B0 80124CB0 90440003 */  lbu       $a0, 3($v0)
/* BB3B4 80124CB4 24020006 */  addiu     $v0, $zero, 6
/* BB3B8 80124CB8 A28204F8 */  sb        $v0, 0x4f8($s4)
/* BB3BC 80124CBC 96820500 */  lhu       $v0, 0x500($s4)
/* BB3C0 80124CC0 00832021 */  addu      $a0, $a0, $v1
/* BB3C4 80124CC4 02040018 */  mult      $s0, $a0
/* BB3C8 80124CC8 A2800468 */  sb        $zero, 0x468($s4)
/* BB3CC 80124CCC 96830462 */  lhu       $v1, 0x462($s4)
/* BB3D0 80124CD0 34420001 */  ori       $v0, $v0, 1
/* BB3D4 80124CD4 A6820500 */  sh        $v0, 0x500($s4)
/* BB3D8 80124CD8 00004012 */  mflo      $t0
/* BB3DC 80124CDC 00681821 */  addu      $v1, $v1, $t0
/* BB3E0 80124CE0 08049580 */  j         L80125600_BBD00
/* BB3E4 80124CE4 A6830466 */   sh       $v1, 0x466($s4)
glabel L80124CE8_BB3E8
/* BB3E8 80124CE8 A2560000 */  sb        $s6, ($s2)
/* BB3EC 80124CEC 26520001 */  addiu     $s2, $s2, 1
/* BB3F0 80124CF0 24020006 */  addiu     $v0, $zero, 6
/* BB3F4 80124CF4 A2420000 */  sb        $v0, ($s2)
/* BB3F8 80124CF8 26520001 */  addiu     $s2, $s2, 1
/* BB3FC 80124CFC 92620000 */  lbu       $v0, ($s3)
/* BB400 80124D00 3C013D80 */  lui       $at, 0x3d80
/* BB404 80124D04 44810000 */  mtc1      $at, $f0
/* BB408 80124D08 26730001 */  addiu     $s3, $s3, 1
/* BB40C 80124D0C A2420000 */  sb        $v0, ($s2)
/* BB410 80124D10 92700000 */  lbu       $s0, ($s3)
/* BB414 80124D14 26520001 */  addiu     $s2, $s2, 1
/* BB418 80124D18 3202000F */  andi      $v0, $s0, 0xf
/* BB41C 80124D1C 44821000 */  mtc1      $v0, $f2
/* BB420 80124D20 00000000 */  nop
/* BB424 80124D24 468010A0 */  cvt.s.w   $f2, $f2
/* BB428 80124D28 46001082 */  mul.s     $f2, $f2, $f0
/* BB42C 80124D2C 00000000 */  nop
/* BB430 80124D30 26730001 */  addiu     $s3, $s3, 1
/* BB434 80124D34 320200FF */  andi      $v0, $s0, 0xff
/* BB438 80124D38 00021102 */  srl       $v0, $v0, 4
/* BB43C 80124D3C 44820000 */  mtc1      $v0, $f0
/* BB440 80124D40 00000000 */  nop
/* BB444 80124D44 46800020 */  cvt.s.w   $f0, $f0
/* BB448 80124D48 46020000 */  add.s     $f0, $f0, $f2
/* BB44C 80124D4C 0804935B */  j         .L80124D6C
/* BB450 80124D50 A2500000 */   sb       $s0, ($s2)
glabel L80124D54_BB454
/* BB454 80124D54 A2560000 */  sb        $s6, ($s2)
/* BB458 80124D58 26520001 */  addiu     $s2, $s2, 1
/* BB45C 80124D5C 3C013F80 */  lui       $at, 0x3f80
/* BB460 80124D60 44810000 */  mtc1      $at, $f0
/* BB464 80124D64 24020007 */  addiu     $v0, $zero, 7
/* BB468 80124D68 A2420000 */  sb        $v0, ($s2)
.L80124D6C:
/* BB46C 80124D6C 26520001 */  addiu     $s2, $s2, 1
/* BB470 80124D70 08049580 */  j         L80125600_BBD00
/* BB474 80124D74 E6800540 */   swc1     $f0, 0x540($s4)
glabel L80124D78_BB478
/* BB478 80124D78 92620000 */  lbu       $v0, ($s3)
/* BB47C 80124D7C 26730001 */  addiu     $s3, $s3, 1
/* BB480 80124D80 A282045E */  sb        $v0, 0x45e($s4)
/* BB484 80124D84 92620000 */  lbu       $v0, ($s3)
/* BB488 80124D88 26730001 */  addiu     $s3, $s3, 1
/* BB48C 80124D8C 08049580 */  j         L80125600_BBD00
/* BB490 80124D90 A282045F */   sb       $v0, 0x45f($s4)
glabel L80124D94_BB494
/* BB494 80124D94 A2560000 */  sb        $s6, ($s2)
/* BB498 80124D98 26520001 */  addiu     $s2, $s2, 1
/* BB49C 80124D9C 24020008 */  addiu     $v0, $zero, 8
/* BB4A0 80124DA0 A2420000 */  sb        $v0, ($s2)
/* BB4A4 80124DA4 26520001 */  addiu     $s2, $s2, 1
/* BB4A8 80124DA8 92620000 */  lbu       $v0, ($s3)
/* BB4AC 80124DAC 08049552 */  j         .L80125548
/* BB4B0 80124DB0 26730001 */   addiu    $s3, $s3, 1
glabel L80124DB4_BB4B4
/* BB4B4 80124DB4 A2560000 */  sb        $s6, ($s2)
/* BB4B8 80124DB8 26520001 */  addiu     $s2, $s2, 1
/* BB4BC 80124DBC 08049552 */  j         .L80125548
/* BB4C0 80124DC0 24020009 */   addiu    $v0, $zero, 9
glabel L80124DC4_BB4C4
/* BB4C4 80124DC4 A2560000 */  sb        $s6, ($s2)
/* BB4C8 80124DC8 26520001 */  addiu     $s2, $s2, 1
/* BB4CC 80124DCC 08049552 */  j         .L80125548
/* BB4D0 80124DD0 2402000A */   addiu    $v0, $zero, 0xa
glabel L80124DD4_BB4D4
/* BB4D4 80124DD4 A2560000 */  sb        $s6, ($s2)
/* BB4D8 80124DD8 26520001 */  addiu     $s2, $s2, 1
/* BB4DC 80124DDC 08049552 */  j         .L80125548
/* BB4E0 80124DE0 2402000B */   addiu    $v0, $zero, 0xb
glabel L80124DE4_BB4E4
/* BB4E4 80124DE4 A2560000 */  sb        $s6, ($s2)
/* BB4E8 80124DE8 26520001 */  addiu     $s2, $s2, 1
/* BB4EC 80124DEC 08049552 */  j         .L80125548
/* BB4F0 80124DF0 2402000C */   addiu    $v0, $zero, 0xc
glabel L80124DF4_BB4F4
/* BB4F4 80124DF4 A2560000 */  sb        $s6, ($s2)
/* BB4F8 80124DF8 26520001 */  addiu     $s2, $s2, 1
/* BB4FC 80124DFC 2402000E */  addiu     $v0, $zero, 0xe
/* BB500 80124E00 A2420000 */  sb        $v0, ($s2)
/* BB504 80124E04 26520001 */  addiu     $s2, $s2, 1
/* BB508 80124E08 92620000 */  lbu       $v0, ($s3)
/* BB50C 80124E0C 26730001 */  addiu     $s3, $s3, 1
/* BB510 80124E10 26B5FFFF */  addiu     $s5, $s5, -1
/* BB514 80124E14 A2420000 */  sb        $v0, ($s2)
/* BB518 80124E18 9282045E */  lbu       $v0, 0x45e($s4)
/* BB51C 80124E1C 26520001 */  addiu     $s2, $s2, 1
/* BB520 80124E20 080493DF */  j         .L80124F7C
/* BB524 80124E24 A682000E */   sh       $v0, 0xe($s4)
glabel L80124E28_BB528
/* BB528 80124E28 A2560000 */  sb        $s6, ($s2)
/* BB52C 80124E2C 26520001 */  addiu     $s2, $s2, 1
/* BB530 80124E30 2402000F */  addiu     $v0, $zero, 0xf
/* BB534 80124E34 A2420000 */  sb        $v0, ($s2)
/* BB538 80124E38 26520001 */  addiu     $s2, $s2, 1
/* BB53C 80124E3C 92620000 */  lbu       $v0, ($s3)
/* BB540 80124E40 26730001 */  addiu     $s3, $s3, 1
/* BB544 80124E44 26B5FFFF */  addiu     $s5, $s5, -1
/* BB548 80124E48 A2420000 */  sb        $v0, ($s2)
/* BB54C 80124E4C 26520001 */  addiu     $s2, $s2, 1
/* BB550 80124E50 92620000 */  lbu       $v0, ($s3)
/* BB554 80124E54 26730001 */  addiu     $s3, $s3, 1
/* BB558 80124E58 A2420000 */  sb        $v0, ($s2)
/* BB55C 80124E5C 26520001 */  addiu     $s2, $s2, 1
/* BB560 80124E60 92620000 */  lbu       $v0, ($s3)
/* BB564 80124E64 26730001 */  addiu     $s3, $s3, 1
/* BB568 80124E68 A2420000 */  sb        $v0, ($s2)
/* BB56C 80124E6C 9282045E */  lbu       $v0, 0x45e($s4)
/* BB570 80124E70 26520001 */  addiu     $s2, $s2, 1
/* BB574 80124E74 080493DF */  j         .L80124F7C
/* BB578 80124E78 A682000E */   sh       $v0, 0xe($s4)
glabel L80124E7C_BB57C
/* BB57C 80124E7C A2560000 */  sb        $s6, ($s2)
/* BB580 80124E80 26520001 */  addiu     $s2, $s2, 1
/* BB584 80124E84 24020010 */  addiu     $v0, $zero, 0x10
/* BB588 80124E88 A2420000 */  sb        $v0, ($s2)
/* BB58C 80124E8C 26520001 */  addiu     $s2, $s2, 1
/* BB590 80124E90 92700000 */  lbu       $s0, ($s3)
/* BB594 80124E94 26730001 */  addiu     $s3, $s3, 1
/* BB598 80124E98 92650000 */  lbu       $a1, ($s3)
/* BB59C 80124E9C 26730001 */  addiu     $s3, $s3, 1
/* BB5A0 80124EA0 3C068016 */  lui       $a2, %hi(D_80159B50)
/* BB5A4 80124EA4 24C69B50 */  addiu     $a2, $a2, %lo(D_80159B50)
/* BB5A8 80124EA8 3C11001D */  lui       $s1, 0x1d
/* BB5AC 80124EAC 2631C310 */  addiu     $s1, $s1, -0x3cf0
/* BB5B0 80124EB0 3C018015 */  lui       $at, %hi(D_8015131C)
/* BB5B4 80124EB4 AC26131C */  sw        $a2, %lo(D_8015131C)($at)
/* BB5B8 80124EB8 00108200 */  sll       $s0, $s0, 8
/* BB5BC 80124EBC 00B08025 */  or        $s0, $a1, $s0
/* BB5C0 80124EC0 00108400 */  sll       $s0, $s0, 0x10
/* BB5C4 80124EC4 00108383 */  sra       $s0, $s0, 0xe
/* BB5C8 80124EC8 3C028009 */  lui       $v0, %hi(D_8008E3D8)
/* BB5CC 80124ECC 00501021 */  addu      $v0, $v0, $s0
/* BB5D0 80124ED0 8C42E3D8 */  lw        $v0, %lo(D_8008E3D8)($v0)
/* BB5D4 80124ED4 26250200 */  addiu     $a1, $s1, 0x200
/* BB5D8 80124ED8 00512021 */  addu      $a0, $v0, $s1
/* BB5DC 80124EDC 0C00A5CF */  jal       dma_copy
/* BB5E0 80124EE0 00452821 */   addu     $a1, $v0, $a1
/* BB5E4 80124EE4 3C058009 */  lui       $a1, %hi(D_8008E94C)
/* BB5E8 80124EE8 00B02821 */  addu      $a1, $a1, $s0
/* BB5EC 80124EEC 8CA5E94C */  lw        $a1, %lo(D_8008E94C)($a1)
/* BB5F0 80124EF0 3C068016 */  lui       $a2, %hi(D_8015C7E0)
/* BB5F4 80124EF4 24C6C7E0 */  addiu     $a2, $a2, %lo(D_8015C7E0)
/* BB5F8 80124EF8 00B12021 */  addu      $a0, $a1, $s1
/* BB5FC 80124EFC 26310020 */  addiu     $s1, $s1, 0x20
/* BB600 80124F00 0C00A5CF */  jal       dma_copy
/* BB604 80124F04 00B12821 */   addu     $a1, $a1, $s1
/* BB608 80124F08 9282045E */  lbu       $v0, 0x45e($s4)
/* BB60C 80124F0C 26B5FFFF */  addiu     $s5, $s5, -1
/* BB610 80124F10 080493DF */  j         .L80124F7C
/* BB614 80124F14 A682000E */   sh       $v0, 0xe($s4)
glabel L80124F18_BB618
/* BB618 80124F18 92620000 */  lbu       $v0, ($s3)
/* BB61C 80124F1C 26730001 */  addiu     $s3, $s3, 1
/* BB620 80124F20 26B5FFFF */  addiu     $s5, $s5, -1
/* BB624 80124F24 A282052B */  sb        $v0, 0x52b($s4)
/* BB628 80124F28 92700000 */  lbu       $s0, ($s3)
/* BB62C 80124F2C 26730001 */  addiu     $s3, $s3, 1
/* BB630 80124F30 92650000 */  lbu       $a1, ($s3)
/* BB634 80124F34 26730001 */  addiu     $s3, $s3, 1
/* BB638 80124F38 00101200 */  sll       $v0, $s0, 8
/* BB63C 80124F3C 00A21025 */  or        $v0, $a1, $v0
/* BB640 80124F40 A682052C */  sh        $v0, 0x52c($s4)
/* BB644 80124F44 92620000 */  lbu       $v0, ($s3)
/* BB648 80124F48 26730001 */  addiu     $s3, $s3, 1
/* BB64C 80124F4C A682052E */  sh        $v0, 0x52e($s4)
/* BB650 80124F50 92620000 */  lbu       $v0, ($s3)
/* BB654 80124F54 26730001 */  addiu     $s3, $s3, 1
/* BB658 80124F58 A2820530 */  sb        $v0, 0x530($s4)
/* BB65C 80124F5C 92620000 */  lbu       $v0, ($s3)
/* BB660 80124F60 26730001 */  addiu     $s3, $s3, 1
/* BB664 80124F64 A2820531 */  sb        $v0, 0x531($s4)
/* BB668 80124F68 92620000 */  lbu       $v0, ($s3)
/* BB66C 80124F6C 26730001 */  addiu     $s3, $s3, 1
/* BB670 80124F70 A2800533 */  sb        $zero, 0x533($s4)
/* BB674 80124F74 A6800534 */  sh        $zero, 0x534($s4)
/* BB678 80124F78 A2820532 */  sb        $v0, 0x532($s4)
.L80124F7C:
/* BB67C 80124F7C 1EA00004 */  bgtz      $s5, .L80124F90
/* BB680 80124F80 00000000 */   nop
/* BB684 80124F84 96820500 */  lhu       $v0, 0x500($s4)
/* BB688 80124F88 34420001 */  ori       $v0, $v0, 1
/* BB68C 80124F8C A6820500 */  sh        $v0, 0x500($s4)
.L80124F90:
/* BB690 80124F90 96830500 */  lhu       $v1, 0x500($s4)
/* BB694 80124F94 30620006 */  andi      $v0, $v1, 6
.L80124F98:
/* BB698 80124F98 1040019D */  beqz      $v0, .L80125610
/* BB69C 80124F9C 3062FFFE */   andi     $v0, $v1, 0xfffe
/* BB6A0 80124FA0 08049580 */  j         L80125600_BBD00
/* BB6A4 80124FA4 A6820500 */   sh       $v0, 0x500($s4)
glabel L80124FA8_BB6A8
/* BB6A8 80124FA8 92700000 */  lbu       $s0, ($s3)
/* BB6AC 80124FAC 12000005 */  beqz      $s0, .L80124FC4
/* BB6B0 80124FB0 26730001 */   addiu    $s3, $s3, 1
/* BB6B4 80124FB4 A2970533 */  sb        $s7, 0x533($s4)
/* BB6B8 80124FB8 A2900532 */  sb        $s0, 0x532($s4)
/* BB6BC 80124FBC 08049580 */  j         L80125600_BBD00
/* BB6C0 80124FC0 A6800534 */   sh       $zero, 0x534($s4)
.L80124FC4:
/* BB6C4 80124FC4 08049580 */  j         L80125600_BBD00
/* BB6C8 80124FC8 A680052C */   sh       $zero, 0x52c($s4)
glabel L80124FCC_BB6CC
/* BB6CC 80124FCC A2560000 */  sb        $s6, ($s2)
/* BB6D0 80124FD0 26520001 */  addiu     $s2, $s2, 1
/* BB6D4 80124FD4 24020011 */  addiu     $v0, $zero, 0x11
/* BB6D8 80124FD8 A2420000 */  sb        $v0, ($s2)
/* BB6DC 80124FDC 26520001 */  addiu     $s2, $s2, 1
/* BB6E0 80124FE0 92620000 */  lbu       $v0, ($s3)
/* BB6E4 80124FE4 26730001 */  addiu     $s3, $s3, 1
/* BB6E8 80124FE8 A2420000 */  sb        $v0, ($s2)
/* BB6EC 80124FEC 26520001 */  addiu     $s2, $s2, 1
/* BB6F0 80124FF0 92620000 */  lbu       $v0, ($s3)
/* BB6F4 80124FF4 26730001 */  addiu     $s3, $s3, 1
/* BB6F8 80124FF8 A2420000 */  sb        $v0, ($s2)
/* BB6FC 80124FFC 26520001 */  addiu     $s2, $s2, 1
/* BB700 80125000 92620000 */  lbu       $v0, ($s3)
/* BB704 80125004 26730001 */  addiu     $s3, $s3, 1
/* BB708 80125008 A2420000 */  sb        $v0, ($s2)
/* BB70C 8012500C 96820500 */  lhu       $v0, 0x500($s4)
/* BB710 80125010 26520001 */  addiu     $s2, $s2, 1
/* BB714 80125014 34420004 */  ori       $v0, $v0, 4
/* BB718 80125018 08049580 */  j         L80125600_BBD00
/* BB71C 8012501C A6820500 */   sh       $v0, 0x500($s4)
glabel L80125020_BB720
/* BB720 80125020 A2560000 */  sb        $s6, ($s2)
/* BB724 80125024 26520001 */  addiu     $s2, $s2, 1
/* BB728 80125028 24020012 */  addiu     $v0, $zero, 0x12
/* BB72C 8012502C A2420000 */  sb        $v0, ($s2)
/* BB730 80125030 26520001 */  addiu     $s2, $s2, 1
/* BB734 80125034 92620000 */  lbu       $v0, ($s3)
/* BB738 80125038 08049552 */  j         .L80125548
/* BB73C 8012503C 26730001 */   addiu    $s3, $s3, 1
glabel L80125040_BB740
/* BB740 80125040 A2560000 */  sb        $s6, ($s2)
/* BB744 80125044 26520001 */  addiu     $s2, $s2, 1
/* BB748 80125048 24020013 */  addiu     $v0, $zero, 0x13
/* BB74C 8012504C A2420000 */  sb        $v0, ($s2)
/* BB750 80125050 26520001 */  addiu     $s2, $s2, 1
/* BB754 80125054 92620000 */  lbu       $v0, ($s3)
/* BB758 80125058 26730001 */  addiu     $s3, $s3, 1
/* BB75C 8012505C 26B5FFFF */  addiu     $s5, $s5, -1
/* BB760 80125060 A2420000 */  sb        $v0, ($s2)
/* BB764 80125064 96820500 */  lhu       $v0, 0x500($s4)
/* BB768 80125068 26520001 */  addiu     $s2, $s2, 1
/* BB76C 8012506C 3042FFFB */  andi      $v0, $v0, 0xfffb
/* BB770 80125070 1EA00163 */  bgtz      $s5, L80125600_BBD00
/* BB774 80125074 A6820500 */   sh       $v0, 0x500($s4)
.L80125078:
/* BB778 80125078 34420001 */  ori       $v0, $v0, 1
/* BB77C 8012507C 08049580 */  j         L80125600_BBD00
/* BB780 80125080 A6820500 */   sh       $v0, 0x500($s4)
glabel L80125084_BB784
/* BB784 80125084 92700000 */  lbu       $s0, ($s3)
/* BB788 80125088 26730001 */  addiu     $s3, $s3, 1
/* BB78C 8012508C 92650000 */  lbu       $a1, ($s3)
/* BB790 80125090 26730001 */  addiu     $s3, $s3, 1
/* BB794 80125094 92640000 */  lbu       $a0, ($s3)
/* BB798 80125098 26730001 */  addiu     $s3, $s3, 1
/* BB79C 8012509C 92660000 */  lbu       $a2, ($s3)
/* BB7A0 801250A0 26730001 */  addiu     $s3, $s3, 1
/* BB7A4 801250A4 00101040 */  sll       $v0, $s0, 1
/* BB7A8 801250A8 02821021 */  addu      $v0, $s4, $v0
/* BB7AC 801250AC 00051A00 */  sll       $v1, $a1, 8
/* BB7B0 801250B0 00831825 */  or        $v1, $a0, $v1
/* BB7B4 801250B4 A44304D0 */  sh        $v1, 0x4d0($v0)
/* BB7B8 801250B8 30C300FF */  andi      $v1, $a2, 0xff
/* BB7BC 801250BC 08049580 */  j         L80125600_BBD00
/* BB7C0 801250C0 A44304DC */   sh       $v1, 0x4dc($v0)
glabel L801250C4_BB7C4
/* BB7C4 801250C4 A2560000 */  sb        $s6, ($s2)
/* BB7C8 801250C8 26520001 */  addiu     $s2, $s2, 1
/* BB7CC 801250CC 08049552 */  j         .L80125548
/* BB7D0 801250D0 24020014 */   addiu    $v0, $zero, 0x14
glabel L801250D4_BB7D4
/* BB7D4 801250D4 24040009 */  addiu     $a0, $zero, 9
/* BB7D8 801250D8 0000282D */  daddu     $a1, $zero, $zero
/* BB7DC 801250DC 00A0302D */  daddu     $a2, $a1, $zero
/* BB7E0 801250E0 0C0526AE */  jal       sfx_play_sound_with_params
/* BB7E4 801250E4 00A0382D */   daddu    $a3, $a1, $zero
/* BB7E8 801250E8 92640000 */  lbu       $a0, ($s3)
/* BB7EC 801250EC 26730001 */  addiu     $s3, $s3, 1
/* BB7F0 801250F0 96830500 */  lhu       $v1, 0x500($s4)
/* BB7F4 801250F4 24020007 */  addiu     $v0, $zero, 7
/* BB7F8 801250F8 A28004E9 */  sb        $zero, 0x4e9($s4)
/* BB7FC 801250FC A28004E8 */  sb        $zero, 0x4e8($s4)
/* BB800 80125100 A28004EE */  sb        $zero, 0x4ee($s4)
/* BB804 80125104 A28204F8 */  sb        $v0, 0x4f8($s4)
/* BB808 80125108 34630001 */  ori       $v1, $v1, 1
/* BB80C 8012510C A28404CE */  sb        $a0, 0x4ce($s4)
/* BB810 80125110 08049580 */  j         L80125600_BBD00
/* BB814 80125114 A6830500 */   sh       $v1, 0x500($s4)
glabel L80125118_BB818
/* BB818 80125118 92620000 */  lbu       $v0, ($s3)
/* BB81C 8012511C 26730001 */  addiu     $s3, $s3, 1
/* BB820 80125120 08049580 */  j         L80125600_BBD00
/* BB824 80125124 A28204EA */   sb       $v0, 0x4ea($s4)
glabel L80125128_BB828
/* BB828 80125128 A2560000 */  sb        $s6, ($s2)
/* BB82C 8012512C 26520001 */  addiu     $s2, $s2, 1
/* BB830 80125130 08049552 */  j         .L80125548
/* BB834 80125134 24020015 */   addiu    $v0, $zero, 0x15
glabel L80125138_BB838
/* BB838 80125138 A2560000 */  sb        $s6, ($s2)
/* BB83C 8012513C 26520001 */  addiu     $s2, $s2, 1
/* BB840 80125140 08049556 */  j         .L80125558
/* BB844 80125144 24020017 */   addiu    $v0, $zero, 0x17
glabel L80125148_BB848
/* BB848 80125148 3C040010 */  lui       $a0, 0x10
/* BB84C 8012514C 34840040 */  ori       $a0, $a0, 0x40
/* BB850 80125150 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BB854 80125154 96830500 */  lhu       $v1, 0x500($s4)
/* BB858 80125158 00441025 */  or        $v0, $v0, $a0
/* BB85C 8012515C 34630001 */  ori       $v1, $v1, 1
/* BB860 80125160 AE8204FC */  sw        $v0, 0x4fc($s4)
/* BB864 80125164 A6830500 */  sh        $v1, 0x500($s4)
/* BB868 80125168 0040182D */  daddu     $v1, $v0, $zero
/* BB86C 8012516C 2402FF7F */  addiu     $v0, $zero, -0x81
/* BB870 80125170 00621824 */  and       $v1, $v1, $v0
/* BB874 80125174 2402FEFF */  addiu     $v0, $zero, -0x101
/* BB878 80125178 00621824 */  and       $v1, $v1, $v0
/* BB87C 8012517C 08049580 */  j         L80125600_BBD00
/* BB880 80125180 AE8304FC */   sw       $v1, 0x4fc($s4)
glabel L80125184_BB884
/* BB884 80125184 A2560000 */  sb        $s6, ($s2)
/* BB888 80125188 26520001 */  addiu     $s2, $s2, 1
/* BB88C 8012518C 08049556 */  j         .L80125558
/* BB890 80125190 24020018 */   addiu    $v0, $zero, 0x18
glabel L80125194_BB894
/* BB894 80125194 A2560000 */  sb        $s6, ($s2)
/* BB898 80125198 26520001 */  addiu     $s2, $s2, 1
/* BB89C 8012519C 08049556 */  j         .L80125558
/* BB8A0 801251A0 24020019 */   addiu    $v0, $zero, 0x19
glabel L801251A4_BB8A4
/* BB8A4 801251A4 A2560000 */  sb        $s6, ($s2)
/* BB8A8 801251A8 26520001 */  addiu     $s2, $s2, 1
/* BB8AC 801251AC 08049556 */  j         .L80125558
/* BB8B0 801251B0 2402001A */   addiu    $v0, $zero, 0x1a
glabel L801251B4_BB8B4
/* BB8B4 801251B4 A2560000 */  sb        $s6, ($s2)
/* BB8B8 801251B8 26520001 */  addiu     $s2, $s2, 1
/* BB8BC 801251BC 08049556 */  j         .L80125558
/* BB8C0 801251C0 2402001B */   addiu    $v0, $zero, 0x1b
glabel L801251C4_BB8C4
/* BB8C4 801251C4 A2560000 */  sb        $s6, ($s2)
/* BB8C8 801251C8 26520001 */  addiu     $s2, $s2, 1
/* BB8CC 801251CC 2402001C */  addiu     $v0, $zero, 0x1c
/* BB8D0 801251D0 A2420000 */  sb        $v0, ($s2)
/* BB8D4 801251D4 26520001 */  addiu     $s2, $s2, 1
/* BB8D8 801251D8 92700000 */  lbu       $s0, ($s3)
/* BB8DC 801251DC 320300FF */  andi      $v1, $s0, 0xff
/* BB8E0 801251E0 2C62000F */  sltiu     $v0, $v1, 0xf
/* BB8E4 801251E4 10400106 */  beqz      $v0, L80125600_BBD00
/* BB8E8 801251E8 26730001 */   addiu    $s3, $s3, 1
/* BB8EC 801251EC 00031080 */  sll       $v0, $v1, 2
/* BB8F0 801251F0 3C018015 */  lui       $at, %hi(jtbl_801504F8)
/* BB8F4 801251F4 00220821 */  addu      $at, $at, $v0
/* BB8F8 801251F8 8C2204F8 */  lw        $v0, %lo(jtbl_801504F8)($at)
/* BB8FC 801251FC 00400008 */  jr        $v0
/* BB900 80125200 00000000 */   nop
glabel L80125204_BB904
/* BB904 80125204 A2500000 */  sb        $s0, ($s2)
/* BB908 80125208 08049580 */  j         L80125600_BBD00
/* BB90C 8012520C 26520001 */   addiu    $s2, $s2, 1
glabel L80125210_BB910
/* BB910 80125210 08049553 */  j         .L8012554C
/* BB914 80125214 A2500000 */   sb       $s0, ($s2)
glabel L80125218_BB918
/* BB918 80125218 A2560000 */  sb        $s6, ($s2)
/* BB91C 8012521C 26520001 */  addiu     $s2, $s2, 1
/* BB920 80125220 08049552 */  j         .L80125548
/* BB924 80125224 2402001D */   addiu    $v0, $zero, 0x1d
.L80125228:
/* BB928 80125228 9282052A */  lbu       $v0, 0x52a($s4)
/* BB92C 8012522C A6800528 */  sh        $zero, 0x528($s4)
/* BB930 80125230 A2820455 */  sb        $v0, 0x455($s4)
/* BB934 80125234 244200F1 */  addiu     $v0, $v0, 0xf1
/* BB938 80125238 A2420000 */  sb        $v0, ($s2)
/* BB93C 8012523C 0804950F */  j         .L8012543C
/* BB940 80125240 26520001 */   addiu    $s2, $s2, 1
glabel L80125244_BB944
/* BB944 80125244 92700000 */  lbu       $s0, ($s3)
/* BB948 80125248 96820528 */  lhu       $v0, 0x528($s4)
/* BB94C 8012524C 14400006 */  bnez      $v0, .L80125268
/* BB950 80125250 2673FFFE */   addiu    $s3, $s3, -2
/* BB954 80125254 92820455 */  lbu       $v0, 0x455($s4)
/* BB958 80125258 A282052A */  sb        $v0, 0x52a($s4)
/* BB95C 8012525C 240200F1 */  addiu     $v0, $zero, 0xf1
/* BB960 80125260 A2420000 */  sb        $v0, ($s2)
/* BB964 80125264 26520001 */  addiu     $s2, $s2, 1
.L80125268:
/* BB968 80125268 00108140 */  sll       $s0, $s0, 5
/* BB96C 8012526C 27A60010 */  addiu     $a2, $sp, 0x10
.L80125270:
/* BB970 80125270 96820528 */  lhu       $v0, 0x528($s4)
/* BB974 80125274 3C088015 */  lui       $t0, %hi(gMessageStringVars)
/* BB978 80125278 25085C38 */  addiu     $t0, $t0, %lo(gMessageStringVars)
/* BB97C 8012527C 24430001 */  addiu     $v1, $v0, 1
/* BB980 80125280 3042FFFF */  andi      $v0, $v0, 0xffff
/* BB984 80125284 00501021 */  addu      $v0, $v0, $s0
/* BB988 80125288 00481021 */  addu      $v0, $v0, $t0
/* BB98C 8012528C A6830528 */  sh        $v1, 0x528($s4)
/* BB990 80125290 90450000 */  lbu       $a1, ($v0)
/* BB994 80125294 30A300FF */  andi      $v1, $a1, 0xff
/* BB998 80125298 2C6200F0 */  sltiu     $v0, $v1, 0xf0
/* BB99C 8012529C 1440004C */  bnez      $v0, .L801253D0
/* BB9A0 801252A0 24040001 */   addiu    $a0, $zero, 1
/* BB9A4 801252A4 2463FF10 */  addiu     $v1, $v1, -0xf0
/* BB9A8 801252A8 2C620010 */  sltiu     $v0, $v1, 0x10
/* BB9AC 801252AC 10400049 */  beqz      $v0, .L801253D4
/* BB9B0 801252B0 00031080 */   sll      $v0, $v1, 2
/* BB9B4 801252B4 3C088015 */  lui       $t0, %hi(D_80150538)
/* BB9B8 801252B8 25080538 */  addiu     $t0, $t0, %lo(D_80150538)
/* BB9BC 801252BC 00481021 */  addu      $v0, $v0, $t0
/* BB9C0 801252C0 8C420000 */  lw        $v0, ($v0)
/* BB9C4 801252C4 00400008 */  jr        $v0
/* BB9C8 801252C8 00000000 */   nop
/* BB9CC 801252CC 96820528 */  lhu       $v0, 0x528($s4)
/* BB9D0 801252D0 3C088015 */  lui       $t0, %hi(gMessageStringVars)
/* BB9D4 801252D4 25085C38 */  addiu     $t0, $t0, %lo(gMessageStringVars)
/* BB9D8 801252D8 00501021 */  addu      $v0, $v0, $s0
/* BB9DC 801252DC 00481021 */  addu      $v0, $v0, $t0
/* BB9E0 801252E0 90420000 */  lbu       $v0, ($v0)
/* BB9E4 801252E4 240800FD */  addiu     $t0, $zero, 0xfd
/* BB9E8 801252E8 10480003 */  beq       $v0, $t0, .L801252F8
/* BB9EC 801252EC 240200F0 */   addiu    $v0, $zero, 0xf0
/* BB9F0 801252F0 080494F5 */  j         .L801253D4
/* BB9F4 801252F4 A3A20010 */   sb       $v0, 0x10($sp)
.L801252F8:
/* BB9F8 801252F8 080494F5 */  j         .L801253D4
/* BB9FC 801252FC 0000202D */   daddu    $a0, $zero, $zero
/* BBA00 80125300 24A200FE */  addiu     $v0, $a1, 0xfe
/* BBA04 80125304 A3A20010 */  sb        $v0, 0x10($sp)
/* BBA08 80125308 24A2010D */  addiu     $v0, $a1, 0x10d
/* BBA0C 8012530C 080494F5 */  j         .L801253D4
/* BBA10 80125310 A2820455 */   sb       $v0, 0x455($s4)
/* BBA14 80125314 240200F5 */  addiu     $v0, $zero, 0xf5
/* BBA18 80125318 080494F5 */  j         .L801253D4
/* BBA1C 8012531C A3A20010 */   sb       $v0, 0x10($sp)
/* BBA20 80125320 A3B60010 */  sb        $s6, 0x10($sp)
/* BBA24 80125324 96820528 */  lhu       $v0, 0x528($s4)
/* BBA28 80125328 3C088015 */  lui       $t0, %hi(gMessageStringVars)
/* BBA2C 8012532C 25085C38 */  addiu     $t0, $t0, %lo(gMessageStringVars)
/* BBA30 80125330 24430001 */  addiu     $v1, $v0, 1
/* BBA34 80125334 3042FFFF */  andi      $v0, $v0, 0xffff
/* BBA38 80125338 00501021 */  addu      $v0, $v0, $s0
/* BBA3C 8012533C 00481021 */  addu      $v0, $v0, $t0
/* BBA40 80125340 A6830528 */  sh        $v1, 0x528($s4)
/* BBA44 80125344 90430000 */  lbu       $v1, ($v0)
/* BBA48 80125348 24020024 */  addiu     $v0, $zero, 0x24
/* BBA4C 8012534C 1062001A */  beq       $v1, $v0, .L801253B8
/* BBA50 80125350 28620025 */   slti     $v0, $v1, 0x25
/* BBA54 80125354 10400005 */  beqz      $v0, .L8012536C
/* BBA58 80125358 24020005 */   addiu    $v0, $zero, 5
/* BBA5C 8012535C 10620008 */  beq       $v1, $v0, .L80125380
/* BBA60 80125360 0000182D */   daddu    $v1, $zero, $zero
/* BBA64 80125364 080494F6 */  j         .L801253D8
/* BBA68 80125368 00000000 */   nop
.L8012536C:
/* BBA6C 8012536C 24020025 */  addiu     $v0, $zero, 0x25
/* BBA70 80125370 10620013 */  beq       $v1, $v0, .L801253C0
/* BBA74 80125374 0000182D */   daddu    $v1, $zero, $zero
/* BBA78 80125378 080494F6 */  j         .L801253D8
/* BBA7C 8012537C 00000000 */   nop
.L80125380:
/* BBA80 80125380 24020004 */  addiu     $v0, $zero, 4
/* BBA84 80125384 A3A20011 */  sb        $v0, 0x11($sp)
/* BBA88 80125388 96820528 */  lhu       $v0, 0x528($s4)
/* BBA8C 8012538C 3C088015 */  lui       $t0, %hi(gMessageStringVars)
/* BBA90 80125390 25085C38 */  addiu     $t0, $t0, %lo(gMessageStringVars)
/* BBA94 80125394 24430001 */  addiu     $v1, $v0, 1
/* BBA98 80125398 3042FFFF */  andi      $v0, $v0, 0xffff
/* BBA9C 8012539C 00501021 */  addu      $v0, $v0, $s0
/* BBAA0 801253A0 00481021 */  addu      $v0, $v0, $t0
/* BBAA4 801253A4 A6830528 */  sh        $v1, 0x528($s4)
/* BBAA8 801253A8 90420000 */  lbu       $v0, ($v0)
/* BBAAC 801253AC 24040003 */  addiu     $a0, $zero, 3
/* BBAB0 801253B0 080494F5 */  j         .L801253D4
/* BBAB4 801253B4 A3A20012 */   sb       $v0, 0x12($sp)
.L801253B8:
/* BBAB8 801253B8 080494F1 */  j         .L801253C4
/* BBABC 801253BC 2402001A */   addiu    $v0, $zero, 0x1a
.L801253C0:
/* BBAC0 801253C0 2402001B */  addiu     $v0, $zero, 0x1b
.L801253C4:
/* BBAC4 801253C4 A3A20011 */  sb        $v0, 0x11($sp)
/* BBAC8 801253C8 080494F5 */  j         .L801253D4
/* BBACC 801253CC 24040002 */   addiu    $a0, $zero, 2
.L801253D0:
/* BBAD0 801253D0 A3A50010 */  sb        $a1, 0x10($sp)
.L801253D4:
/* BBAD4 801253D4 0000182D */  daddu     $v1, $zero, $zero
.L801253D8:
/* BBAD8 801253D8 10800009 */  beqz      $a0, .L80125400
/* BBADC 801253DC 00000000 */   nop
.L801253E0:
/* BBAE0 801253E0 26B5FFFF */  addiu     $s5, $s5, -1
/* BBAE4 801253E4 00C31021 */  addu      $v0, $a2, $v1
/* BBAE8 801253E8 90420000 */  lbu       $v0, ($v0)
/* BBAEC 801253EC 24630001 */  addiu     $v1, $v1, 1
/* BBAF0 801253F0 A2420000 */  sb        $v0, ($s2)
/* BBAF4 801253F4 0064102A */  slt       $v0, $v1, $a0
/* BBAF8 801253F8 1440FFF9 */  bnez      $v0, .L801253E0
/* BBAFC 801253FC 26520001 */   addiu    $s2, $s2, 1
.L80125400:
/* BBB00 80125400 96820528 */  lhu       $v0, 0x528($s4)
/* BBB04 80125404 3C088015 */  lui       $t0, %hi(gMessageStringVars)
/* BBB08 80125408 25085C38 */  addiu     $t0, $t0, %lo(gMessageStringVars)
/* BBB0C 8012540C 00501021 */  addu      $v0, $v0, $s0
/* BBB10 80125410 00481021 */  addu      $v0, $v0, $t0
/* BBB14 80125414 90420000 */  lbu       $v0, ($v0)
/* BBB18 80125418 240800FD */  addiu     $t0, $zero, 0xfd
/* BBB1C 8012541C 5048FF82 */  beql      $v0, $t0, .L80125228
/* BBB20 80125420 26730003 */   addiu    $s3, $s3, 3
/* BBB24 80125424 96820500 */  lhu       $v0, 0x500($s4)
/* BBB28 80125428 30420006 */  andi      $v0, $v0, 6
/* BBB2C 8012542C 1440FF90 */  bnez      $v0, .L80125270
/* BBB30 80125430 00000000 */   nop
/* BBB34 80125434 1EA0FF8E */  bgtz      $s5, .L80125270
/* BBB38 80125438 00000000 */   nop
.L8012543C:
/* BBB3C 8012543C 96840500 */  lhu       $a0, 0x500($s4)
/* BBB40 80125440 30820006 */  andi      $v0, $a0, 6
/* BBB44 80125444 54400066 */  bnel      $v0, $zero, .L801255E0
/* BBB48 80125448 0280202D */   daddu    $a0, $s4, $zero
/* BBB4C 8012544C 5EA00064 */  bgtzl     $s5, .L801255E0
/* BBB50 80125450 0280202D */   daddu    $a0, $s4, $zero
/* BBB54 80125454 9283045E */  lbu       $v1, 0x45e($s4)
/* BBB58 80125458 34820001 */  ori       $v0, $a0, 1
/* BBB5C 8012545C A6820500 */  sh        $v0, 0x500($s4)
/* BBB60 80125460 A683000E */  sh        $v1, 0xe($s4)
/* BBB64 80125464 08049578 */  j         .L801255E0
/* BBB68 80125468 0280202D */   daddu    $a0, $s4, $zero
glabel L8012546C_BBB6C
/* BBB6C 8012546C 92700000 */  lbu       $s0, ($s3)
/* BBB70 80125470 3C04802F */  lui       $a0, %hi(D_802EB620)
/* BBB74 80125474 2484B620 */  addiu     $a0, $a0, %lo(D_802EB620)
/* BBB78 80125478 320300FF */  andi      $v1, $s0, 0xff
/* BBB7C 8012547C 00031040 */  sll       $v0, $v1, 1
/* BBB80 80125480 00431021 */  addu      $v0, $v0, $v1
/* BBB84 80125484 00021080 */  sll       $v0, $v0, 2
/* BBB88 80125488 00441021 */  addu      $v0, $v0, $a0
/* BBB8C 8012548C A2900518 */  sb        $s0, 0x518($s4)
/* BBB90 80125490 8C430000 */  lw        $v1, ($v0)
/* BBB94 80125494 AE830520 */  sw        $v1, 0x520($s4)
/* BBB98 80125498 8C430004 */  lw        $v1, 4($v0)
/* BBB9C 8012549C AE830524 */  sw        $v1, 0x524($s4)
/* BBBA0 801254A0 9442000A */  lhu       $v0, 0xa($v0)
/* BBBA4 801254A4 26730001 */  addiu     $s3, $s3, 1
/* BBBA8 801254A8 08049580 */  j         L80125600_BBD00
/* BBBAC 801254AC A682051C */   sh       $v0, 0x51c($s4)
glabel L801254B0_BBBB0
/* BBBB0 801254B0 92620000 */  lbu       $v0, ($s3)
/* BBBB4 801254B4 26730001 */  addiu     $s3, $s3, 1
/* BBBB8 801254B8 08049580 */  j         L80125600_BBD00
/* BBBBC 801254BC A2820519 */   sb       $v0, 0x519($s4)
glabel L801254C0_BBBC0
/* BBBC0 801254C0 92700000 */  lbu       $s0, ($s3)
/* BBBC4 801254C4 26730001 */  addiu     $s3, $s3, 1
/* BBBC8 801254C8 92650000 */  lbu       $a1, ($s3)
/* BBBCC 801254CC 26730001 */  addiu     $s3, $s3, 1
/* BBBD0 801254D0 92640000 */  lbu       $a0, ($s3)
/* BBBD4 801254D4 26730001 */  addiu     $s3, $s3, 1
/* BBBD8 801254D8 92660000 */  lbu       $a2, ($s3)
/* BBBDC 801254DC 26730001 */  addiu     $s3, $s3, 1
/* BBBE0 801254E0 00101600 */  sll       $v0, $s0, 0x18
/* BBBE4 801254E4 00051C00 */  sll       $v1, $a1, 0x10
/* BBBE8 801254E8 00431021 */  addu      $v0, $v0, $v1
/* BBBEC 801254EC 00041A00 */  sll       $v1, $a0, 8
/* BBBF0 801254F0 00431021 */  addu      $v0, $v0, $v1
/* BBBF4 801254F4 00C21025 */  or        $v0, $a2, $v0
/* BBBF8 801254F8 AE820520 */  sw        $v0, 0x520($s4)
/* BBBFC 801254FC 92700000 */  lbu       $s0, ($s3)
/* BBC00 80125500 26730001 */  addiu     $s3, $s3, 1
/* BBC04 80125504 92650000 */  lbu       $a1, ($s3)
/* BBC08 80125508 26730001 */  addiu     $s3, $s3, 1
/* BBC0C 8012550C 92640000 */  lbu       $a0, ($s3)
/* BBC10 80125510 26730001 */  addiu     $s3, $s3, 1
/* BBC14 80125514 92660000 */  lbu       $a2, ($s3)
/* BBC18 80125518 26730001 */  addiu     $s3, $s3, 1
/* BBC1C 8012551C 00101600 */  sll       $v0, $s0, 0x18
/* BBC20 80125520 00051C00 */  sll       $v1, $a1, 0x10
/* BBC24 80125524 00431021 */  addu      $v0, $v0, $v1
/* BBC28 80125528 00041A00 */  sll       $v1, $a0, 8
/* BBC2C 8012552C 00431021 */  addu      $v0, $v0, $v1
/* BBC30 80125530 00C21025 */  or        $v0, $a2, $v0
/* BBC34 80125534 08049580 */  j         L80125600_BBD00
/* BBC38 80125538 AE820524 */   sw       $v0, 0x524($s4)
glabel L8012553C_BBC3C
/* BBC3C 8012553C A2560000 */  sb        $s6, ($s2)
/* BBC40 80125540 26520001 */  addiu     $s2, $s2, 1
/* BBC44 80125544 2402001E */  addiu     $v0, $zero, 0x1e
.L80125548:
/* BBC48 80125548 A2420000 */  sb        $v0, ($s2)
.L8012554C:
/* BBC4C 8012554C 26520001 */  addiu     $s2, $s2, 1
/* BBC50 80125550 92620000 */  lbu       $v0, ($s3)
/* BBC54 80125554 26730001 */  addiu     $s3, $s3, 1
.L80125558:
/* BBC58 80125558 A2420000 */  sb        $v0, ($s2)
/* BBC5C 8012555C 08049580 */  j         L80125600_BBD00
/* BBC60 80125560 26520001 */   addiu    $s2, $s2, 1
glabel L80125564_BBC64
/* BBC64 80125564 92620000 */  lbu       $v0, ($s3)
/* BBC68 80125568 10400005 */  beqz      $v0, .L80125580
/* BBC6C 8012556C 26730001 */   addiu    $s3, $s3, 1
/* BBC70 80125570 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BBC74 80125574 3C030004 */  lui       $v1, 4
/* BBC78 80125578 0804957F */  j         .L801255FC
/* BBC7C 8012557C 00431025 */   or       $v0, $v0, $v1
.L80125580:
/* BBC80 80125580 3C03FFFB */  lui       $v1, 0xfffb
/* BBC84 80125584 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BBC88 80125588 3463FFFF */  ori       $v1, $v1, 0xffff
/* BBC8C 8012558C 0804957F */  j         .L801255FC
/* BBC90 80125590 00431024 */   and      $v0, $v0, $v1
glabel L80125594_BBC94
/* BBC94 80125594 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BBC98 80125598 3C030008 */  lui       $v1, 8
/* BBC9C 8012559C 0804957F */  j         .L801255FC
/* BBCA0 801255A0 00431025 */   or       $v0, $v0, $v1
glabel L801255A4_BBCA4
/* BBCA4 801255A4 A2450000 */  sb        $a1, ($s2)
/* BBCA8 801255A8 26520001 */  addiu     $s2, $s2, 1
/* BBCAC 801255AC 92820455 */  lbu       $v0, 0x455($s4)
/* BBCB0 801255B0 14400009 */  bnez      $v0, .L801255D8
/* BBCB4 801255B4 26B5FFFF */   addiu    $s5, $s5, -1
/* BBCB8 801255B8 30A300FF */  andi      $v1, $a1, 0xff
/* BBCBC 801255BC 240200C3 */  addiu     $v0, $zero, 0xc3
/* BBCC0 801255C0 14620006 */  bne       $v1, $v0, .L801255DC
/* BBCC4 801255C4 0280202D */   daddu    $a0, $s4, $zero
/* BBCC8 801255C8 8E8204FC */  lw        $v0, 0x4fc($s4)
/* BBCCC 801255CC 2403FF7F */  addiu     $v1, $zero, -0x81
/* BBCD0 801255D0 0804957F */  j         .L801255FC
/* BBCD4 801255D4 00431024 */   and      $v0, $v0, $v1
.L801255D8:
/* BBCD8 801255D8 0280202D */  daddu     $a0, $s4, $zero
.L801255DC:
/* BBCDC 801255DC 30A500FF */  andi      $a1, $a1, 0xff
.L801255E0:
/* BBCE0 801255E0 0C04910D */  jal       msg_play_speech_sound
/* BBCE4 801255E4 00000000 */   nop
/* BBCE8 801255E8 8E8304FC */  lw        $v1, 0x4fc($s4)
/* BBCEC 801255EC 3C020080 */  lui       $v0, 0x80
/* BBCF0 801255F0 00621024 */  and       $v0, $v1, $v0
/* BBCF4 801255F4 10400002 */  beqz      $v0, L80125600_BBD00
/* BBCF8 801255F8 34620080 */   ori      $v0, $v1, 0x80
.L801255FC:
/* BBCFC 801255FC AE8204FC */  sw        $v0, 0x4fc($s4)
glabel L80125600_BBD00
/* BBD00 80125600 96820500 */  lhu       $v0, 0x500($s4)
/* BBD04 80125604 30420006 */  andi      $v0, $v0, 6
/* BBD08 80125608 14400008 */  bnez      $v0, .L8012562C
/* BBD0C 8012560C 00000000 */   nop
.L80125610:
/* BBD10 80125610 1EA00006 */  bgtz      $s5, .L8012562C
/* BBD14 80125614 00000000 */   nop
/* BBD18 80125618 96820500 */  lhu       $v0, 0x500($s4)
/* BBD1C 8012561C 9283045E */  lbu       $v1, 0x45e($s4)
/* BBD20 80125620 34420001 */  ori       $v0, $v0, 1
/* BBD24 80125624 A6820500 */  sh        $v0, 0x500($s4)
/* BBD28 80125628 A683000E */  sh        $v1, 0xe($s4)
.L8012562C:
/* BBD2C 8012562C 96820500 */  lhu       $v0, 0x500($s4)
/* BBD30 80125630 30420001 */  andi      $v0, $v0, 1
/* BBD34 80125634 1040FBE6 */  beqz      $v0, .L801245D0
/* BBD38 80125638 00000000 */   nop
/* BBD3C 8012563C 13C00004 */  beqz      $fp, .L80125650
/* BBD40 80125640 240800FD */   addiu    $t0, $zero, 0xfd
/* BBD44 80125644 9262FFFF */  lbu       $v0, -1($s3)
/* BBD48 80125648 1448FBE1 */  bne       $v0, $t0, .L801245D0
/* BBD4C 8012564C 24152710 */   addiu    $s5, $zero, 0x2710
.L80125650:
/* BBD50 80125650 2642FFF0 */  addiu     $v0, $s2, -0x10
/* BBD54 80125654 8E830000 */  lw        $v1, ($s4)
/* BBD58 80125658 00541023 */  subu      $v0, $v0, $s4
/* BBD5C 8012565C A6820004 */  sh        $v0, 4($s4)
/* BBD60 80125660 240200FB */  addiu     $v0, $zero, 0xfb
/* BBD64 80125664 A6800500 */  sh        $zero, 0x500($s4)
/* BBD68 80125668 02631823 */  subu      $v1, $s3, $v1
/* BBD6C 8012566C A683000C */  sh        $v1, 0xc($s4)
/* BBD70 80125670 A2420000 */  sb        $v0, ($s2)
/* BBD74 80125674 8FBF0044 */  lw        $ra, 0x44($sp)
/* BBD78 80125678 8FBE0040 */  lw        $fp, 0x40($sp)
/* BBD7C 8012567C 8FB7003C */  lw        $s7, 0x3c($sp)
/* BBD80 80125680 8FB60038 */  lw        $s6, 0x38($sp)
/* BBD84 80125684 8FB50034 */  lw        $s5, 0x34($sp)
/* BBD88 80125688 8FB40030 */  lw        $s4, 0x30($sp)
/* BBD8C 8012568C 8FB3002C */  lw        $s3, 0x2c($sp)
/* BBD90 80125690 8FB20028 */  lw        $s2, 0x28($sp)
/* BBD94 80125694 8FB10024 */  lw        $s1, 0x24($sp)
/* BBD98 80125698 8FB00020 */  lw        $s0, 0x20($sp)
/* BBD9C 8012569C 03E00008 */  jr        $ra
/* BBDA0 801256A0 27BD0048 */   addiu    $sp, $sp, 0x48
