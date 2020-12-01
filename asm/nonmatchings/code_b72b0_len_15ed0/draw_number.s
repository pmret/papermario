.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_number
/* BDD9C 8012769C 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* BDDA0 801276A0 AFB200A8 */  sw        $s2, 0xa8($sp)
/* BDDA4 801276A4 AFB500B4 */  sw        $s5, 0xb4($sp)
/* BDDA8 801276A8 00E0A82D */  daddu     $s5, $a3, $zero
/* BDDAC 801276AC 3C028015 */  lui       $v0, %hi(D_8014C340)
/* BDDB0 801276B0 2442C340 */  addiu     $v0, $v0, %lo(D_8014C340)
/* BDDB4 801276B4 00151880 */  sll       $v1, $s5, 2
/* BDDB8 801276B8 00751821 */  addu      $v1, $v1, $s5
/* BDDBC 801276BC 00031880 */  sll       $v1, $v1, 2
/* BDDC0 801276C0 00621821 */  addu      $v1, $v1, $v0
/* BDDC4 801276C4 AFB400B0 */  sw        $s4, 0xb0($sp)
/* BDDC8 801276C8 24D4FFFE */  addiu     $s4, $a2, -2
/* BDDCC 801276CC AFB100A4 */  sw        $s1, 0xa4($sp)
/* BDDD0 801276D0 97B100E2 */  lhu       $s1, 0xe2($sp)
/* BDDD4 801276D4 2E8200F1 */  sltiu     $v0, $s4, 0xf1
/* BDDD8 801276D8 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* BDDDC 801276DC AFBE00C0 */  sw        $fp, 0xc0($sp)
/* BDDE0 801276E0 AFB700BC */  sw        $s7, 0xbc($sp)
/* BDDE4 801276E4 AFB600B8 */  sw        $s6, 0xb8($sp)
/* BDDE8 801276E8 AFB300AC */  sw        $s3, 0xac($sp)
/* BDDEC 801276EC AFB000A0 */  sw        $s0, 0xa0($sp)
/* BDDF0 801276F0 8C7E0000 */  lw        $fp, ($v1)
/* BDDF4 801276F4 90770004 */  lbu       $s7, 4($v1)
/* BDDF8 801276F8 10400111 */  beqz      $v0, .L80127B40
/* BDDFC 801276FC 00A0902D */   daddu    $s2, $a1, $zero
/* BDE00 80127700 27A50010 */  addiu     $a1, $sp, 0x10
/* BDE04 80127704 0C00A531 */  jal       int_to_string
/* BDE08 80127708 2406000A */   addiu    $a2, $zero, 0xa
/* BDE0C 8012770C 0000802D */  daddu     $s0, $zero, $zero
/* BDE10 80127710 27A50010 */  addiu     $a1, $sp, 0x10
/* BDE14 80127714 27A40028 */  addiu     $a0, $sp, 0x28
/* BDE18 80127718 00B01021 */  addu      $v0, $a1, $s0
.L8012771C:
/* BDE1C 8012771C 90420000 */  lbu       $v0, ($v0)
/* BDE20 80127720 1040000B */  beqz      $v0, .L80127750
/* BDE24 80127724 2443FFD0 */   addiu    $v1, $v0, -0x30
/* BDE28 80127728 306200FF */  andi      $v0, $v1, 0xff
/* BDE2C 8012772C 2C42000A */  sltiu     $v0, $v0, 0xa
/* BDE30 80127730 50400004 */  beql      $v0, $zero, .L80127744
/* BDE34 80127734 26100001 */   addiu    $s0, $s0, 1
/* BDE38 80127738 00901021 */  addu      $v0, $a0, $s0
/* BDE3C 8012773C A0430000 */  sb        $v1, ($v0)
/* BDE40 80127740 26100001 */  addiu     $s0, $s0, 1
.L80127744:
/* BDE44 80127744 2A02000A */  slti      $v0, $s0, 0xa
/* BDE48 80127748 1440FFF4 */  bnez      $v0, .L8012771C
/* BDE4C 8012774C 00B01021 */   addu     $v0, $a1, $s0
.L80127750:
/* BDE50 80127750 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* BDE54 80127754 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* BDE58 80127758 0240302D */  daddu     $a2, $s2, $zero
/* BDE5C 8012775C 8C620000 */  lw        $v0, ($v1)
/* BDE60 80127760 0040202D */  daddu     $a0, $v0, $zero
/* BDE64 80127764 24420008 */  addiu     $v0, $v0, 8
/* BDE68 80127768 AC620000 */  sw        $v0, ($v1)
/* BDE6C 8012776C 3C02DE00 */  lui       $v0, %hi(D_DDFFC368)
/* BDE70 80127770 AC820000 */  sw        $v0, ($a0)
/* BDE74 80127774 3C028015 */  lui       $v0, %hi(D_8014C368)
/* BDE78 80127778 2442C368 */  addiu     $v0, $v0, %lo(D_DDFFC368)
/* BDE7C 8012777C AC820004 */  sw        $v0, 4($a0)
/* BDE80 80127780 32220001 */  andi      $v0, $s1, 1
/* BDE84 80127784 1040001E */  beqz      $v0, .L80127800
/* BDE88 80127788 0200982D */   daddu    $s3, $s0, $zero
/* BDE8C 8012778C 2610FFFF */  addiu     $s0, $s0, -1
/* BDE90 80127790 06000035 */  bltz      $s0, .L80127868
/* BDE94 80127794 00151080 */   sll      $v0, $s5, 2
/* BDE98 80127798 32290002 */  andi      $t1, $s1, 2
/* BDE9C 8012779C 3C058015 */  lui       $a1, %hi(D_8014C340)
/* BDEA0 801277A0 24A5C340 */  addiu     $a1, $a1, %lo(D_8014C340)
/* BDEA4 801277A4 00551021 */  addu      $v0, $v0, $s5
/* BDEA8 801277A8 00022080 */  sll       $a0, $v0, 2
/* BDEAC 801277AC 00854021 */  addu      $t0, $a0, $a1
/* BDEB0 801277B0 27A70028 */  addiu     $a3, $sp, 0x28
/* BDEB4 801277B4 27A30040 */  addiu     $v1, $sp, 0x40
/* BDEB8 801277B8 00101080 */  sll       $v0, $s0, 2
/* BDEBC 801277BC 00431821 */  addu      $v1, $v0, $v1
.L801277C0:
/* BDEC0 801277C0 11200004 */  beqz      $t1, .L801277D4
/* BDEC4 801277C4 00F01021 */   addu     $v0, $a3, $s0
/* BDEC8 801277C8 91020011 */  lbu       $v0, 0x11($t0)
/* BDECC 801277CC 08049DFA */  j         .L801277E8
/* BDED0 801277D0 00C23023 */   subu     $a2, $a2, $v0
.L801277D4:
/* BDED4 801277D4 90420000 */  lbu       $v0, ($v0)
/* BDED8 801277D8 00441021 */  addu      $v0, $v0, $a0
/* BDEDC 801277DC 00451021 */  addu      $v0, $v0, $a1
/* BDEE0 801277E0 90420007 */  lbu       $v0, 7($v0)
/* BDEE4 801277E4 00C23023 */  subu      $a2, $a2, $v0
.L801277E8:
/* BDEE8 801277E8 AC660000 */  sw        $a2, ($v1)
/* BDEEC 801277EC 2610FFFF */  addiu     $s0, $s0, -1
/* BDEF0 801277F0 0601FFF3 */  bgez      $s0, .L801277C0
/* BDEF4 801277F4 2463FFFC */   addiu    $v1, $v1, -4
/* BDEF8 801277F8 08049E1B */  j         .L8012786C
/* BDEFC 801277FC 32220004 */   andi     $v0, $s1, 4
.L80127800:
/* BDF00 80127800 1A600019 */  blez      $s3, .L80127868
/* BDF04 80127804 0000802D */   daddu    $s0, $zero, $zero
/* BDF08 80127808 32290002 */  andi      $t1, $s1, 2
/* BDF0C 8012780C 3C058015 */  lui       $a1, %hi(D_8014C340)
/* BDF10 80127810 24A5C340 */  addiu     $a1, $a1, %lo(D_8014C340)
/* BDF14 80127814 00151080 */  sll       $v0, $s5, 2
/* BDF18 80127818 00551021 */  addu      $v0, $v0, $s5
/* BDF1C 8012781C 00022080 */  sll       $a0, $v0, 2
/* BDF20 80127820 00854021 */  addu      $t0, $a0, $a1
/* BDF24 80127824 27A70028 */  addiu     $a3, $sp, 0x28
/* BDF28 80127828 27A30040 */  addiu     $v1, $sp, 0x40
.L8012782C:
/* BDF2C 8012782C 11200004 */  beqz      $t1, .L80127840
/* BDF30 80127830 AC660000 */   sw       $a2, ($v1)
/* BDF34 80127834 91020011 */  lbu       $v0, 0x11($t0)
/* BDF38 80127838 08049E16 */  j         .L80127858
/* BDF3C 8012783C 00C23021 */   addu     $a2, $a2, $v0
.L80127840:
/* BDF40 80127840 00F01021 */  addu      $v0, $a3, $s0
/* BDF44 80127844 90420000 */  lbu       $v0, ($v0)
/* BDF48 80127848 00441021 */  addu      $v0, $v0, $a0
/* BDF4C 8012784C 00451021 */  addu      $v0, $v0, $a1
/* BDF50 80127850 90420007 */  lbu       $v0, 7($v0)
/* BDF54 80127854 00C23021 */  addu      $a2, $a2, $v0
.L80127858:
/* BDF58 80127858 26100001 */  addiu     $s0, $s0, 1
/* BDF5C 8012785C 0213102A */  slt       $v0, $s0, $s3
/* BDF60 80127860 1440FFF2 */  bnez      $v0, .L8012782C
/* BDF64 80127864 24630004 */   addiu    $v1, $v1, 4
.L80127868:
/* BDF68 80127868 32220004 */  andi      $v0, $s1, 4
.L8012786C:
/* BDF6C 8012786C 10400038 */  beqz      $v0, .L80127950
/* BDF70 80127870 00000000 */   nop      
/* BDF74 80127874 1A600036 */  blez      $s3, .L80127950
/* BDF78 80127878 0000802D */   daddu    $s0, $zero, $zero
/* BDF7C 8012787C 3C11800A */  lui       $s1, %hi(D_8009A66C)
/* BDF80 80127880 2631A66C */  addiu     $s1, $s1, %lo(D_8009A66C)
/* BDF84 80127884 3C12E700 */  lui       $s2, 0xe700
/* BDF88 80127888 3C16E200 */  lui       $s6, 0xe200
/* BDF8C 8012788C 36D6001C */  ori       $s6, $s6, 0x1c
.L80127890:
/* BDF90 80127890 3C040050 */  lui       $a0, 0x50
/* BDF94 80127894 34844240 */  ori       $a0, $a0, 0x4240
/* BDF98 80127898 3C07FCFF */  lui       $a3, 0xfcff
/* BDF9C 8012789C 34E797FF */  ori       $a3, $a3, 0x97ff
/* BDFA0 801278A0 3C06FF2D */  lui       $a2, 0xff2d
/* BDFA4 801278A4 34C6FEFF */  ori       $a2, $a2, 0xfeff
/* BDFA8 801278A8 3C082828 */  lui       $t0, 0x2828
/* BDFAC 801278AC 35082848 */  ori       $t0, $t0, 0x2848
/* BDFB0 801278B0 8E230000 */  lw        $v1, ($s1)
/* BDFB4 801278B4 02A0282D */  daddu     $a1, $s5, $zero
/* BDFB8 801278B8 0060102D */  daddu     $v0, $v1, $zero
/* BDFBC 801278BC 24630008 */  addiu     $v1, $v1, 8
/* BDFC0 801278C0 AE230000 */  sw        $v1, ($s1)
/* BDFC4 801278C4 AC520000 */  sw        $s2, ($v0)
/* BDFC8 801278C8 AC400004 */  sw        $zero, 4($v0)
/* BDFCC 801278CC 24620008 */  addiu     $v0, $v1, 8
/* BDFD0 801278D0 AE220000 */  sw        $v0, ($s1)
/* BDFD4 801278D4 24620010 */  addiu     $v0, $v1, 0x10
/* BDFD8 801278D8 AC760000 */  sw        $s6, ($v1)
/* BDFDC 801278DC AC640004 */  sw        $a0, 4($v1)
/* BDFE0 801278E0 AE220000 */  sw        $v0, ($s1)
/* BDFE4 801278E4 24620018 */  addiu     $v0, $v1, 0x18
/* BDFE8 801278E8 AC670008 */  sw        $a3, 8($v1)
/* BDFEC 801278EC AC66000C */  sw        $a2, 0xc($v1)
/* BDFF0 801278F0 AE220000 */  sw        $v0, ($s1)
/* BDFF4 801278F4 3C02FA00 */  lui       $v0, %hi(D_FA000028)
/* BDFF8 801278F8 AC620010 */  sw        $v0, 0x10($v1)
/* BDFFC 801278FC 03B01021 */  addu      $v0, $sp, $s0
/* BE000 80127900 AC680014 */  sw        $t0, 0x14($v1)
/* BE004 80127904 90420028 */  lbu       $v0, %lo(D_FA000028)($v0)
/* BE008 80127908 00101880 */  sll       $v1, $s0, 2
/* BE00C 8012790C 00570018 */  mult      $v0, $s7
/* BE010 80127910 03A31021 */  addu      $v0, $sp, $v1
/* BE014 80127914 8C460040 */  lw        $a2, 0x40($v0)
/* BE018 80127918 26870002 */  addiu     $a3, $s4, 2
/* BE01C 8012791C 24C60002 */  addiu     $a2, $a2, 2
/* BE020 80127920 00005012 */  mflo      $t2
/* BE024 80127924 0C049D30 */  jal       draw_digit
/* BE028 80127928 03CA2021 */   addu     $a0, $fp, $t2
/* BE02C 8012792C 8E220000 */  lw        $v0, ($s1)
/* BE030 80127930 26100001 */  addiu     $s0, $s0, 1
/* BE034 80127934 0040182D */  daddu     $v1, $v0, $zero
/* BE038 80127938 24420008 */  addiu     $v0, $v0, 8
/* BE03C 8012793C AE220000 */  sw        $v0, ($s1)
/* BE040 80127940 0213102A */  slt       $v0, $s0, $s3
/* BE044 80127944 AC720000 */  sw        $s2, ($v1)
/* BE048 80127948 1440FFD1 */  bnez      $v0, .L80127890
/* BE04C 8012794C AC600004 */   sw       $zero, 4($v1)
.L80127950:
/* BE050 80127950 8FAA00DC */  lw        $t2, 0xdc($sp)
/* BE054 80127954 240200FF */  addiu     $v0, $zero, 0xff
/* BE058 80127958 15420015 */  bne       $t2, $v0, .L801279B0
/* BE05C 8012795C 3C07E200 */   lui      $a3, 0xe200
/* BE060 80127960 34E7001C */  ori       $a3, $a3, 0x1c
/* BE064 80127964 3C050F0A */  lui       $a1, 0xf0a
/* BE068 80127968 34A57008 */  ori       $a1, $a1, 0x7008
/* BE06C 8012796C 3C08FCFF */  lui       $t0, 0xfcff
/* BE070 80127970 3508FFFF */  ori       $t0, $t0, 0xffff
/* BE074 80127974 3C06FFFC */  lui       $a2, 0xfffc
/* BE078 80127978 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* BE07C 8012797C 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* BE080 80127980 8C820000 */  lw        $v0, ($a0)
/* BE084 80127984 34C6F279 */  ori       $a2, $a2, 0xf279
/* BE088 80127988 0040182D */  daddu     $v1, $v0, $zero
/* BE08C 8012798C 24420008 */  addiu     $v0, $v0, 8
/* BE090 80127990 AC820000 */  sw        $v0, ($a0)
/* BE094 80127994 AC670000 */  sw        $a3, ($v1)
/* BE098 80127998 AC650004 */  sw        $a1, 4($v1)
/* BE09C 8012799C 24430008 */  addiu     $v1, $v0, 8
/* BE0A0 801279A0 AC830000 */  sw        $v1, ($a0)
/* BE0A4 801279A4 AC480000 */  sw        $t0, ($v0)
/* BE0A8 801279A8 08049E87 */  j         .L80127A1C
/* BE0AC 801279AC AC460004 */   sw       $a2, 4($v0)
.L801279B0:
/* BE0B0 801279B0 34E7001C */  ori       $a3, $a3, 0x1c
/* BE0B4 801279B4 3C050050 */  lui       $a1, 0x50
/* BE0B8 801279B8 34A54240 */  ori       $a1, $a1, 0x4240
/* BE0BC 801279BC 3C08FCFF */  lui       $t0, 0xfcff
/* BE0C0 801279C0 3508B3FF */  ori       $t0, $t0, 0xb3ff
/* BE0C4 801279C4 3C06FF64 */  lui       $a2, 0xff64
/* BE0C8 801279C8 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* BE0CC 801279CC 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* BE0D0 801279D0 8C830000 */  lw        $v1, ($a0)
/* BE0D4 801279D4 34C6FE7F */  ori       $a2, $a2, 0xfe7f
/* BE0D8 801279D8 0060102D */  daddu     $v0, $v1, $zero
/* BE0DC 801279DC 24630008 */  addiu     $v1, $v1, 8
/* BE0E0 801279E0 AC830000 */  sw        $v1, ($a0)
/* BE0E4 801279E4 AC470000 */  sw        $a3, ($v0)
/* BE0E8 801279E8 AC450004 */  sw        $a1, 4($v0)
/* BE0EC 801279EC 24620008 */  addiu     $v0, $v1, 8
/* BE0F0 801279F0 AC820000 */  sw        $v0, ($a0)
/* BE0F4 801279F4 24620010 */  addiu     $v0, $v1, 0x10
/* BE0F8 801279F8 AC680000 */  sw        $t0, ($v1)
/* BE0FC 801279FC AC660004 */  sw        $a2, 4($v1)
/* BE100 80127A00 AC820000 */  sw        $v0, ($a0)
/* BE104 80127A04 3C02FA00 */  lui       $v0, 0xfa00
/* BE108 80127A08 AC620008 */  sw        $v0, 8($v1)
/* BE10C 80127A0C 8FAA00DC */  lw        $t2, 0xdc($sp)
/* BE110 80127A10 2402FF00 */  addiu     $v0, $zero, -0x100
/* BE114 80127A14 01421025 */  or        $v0, $t2, $v0
/* BE118 80127A18 AC62000C */  sw        $v0, 0xc($v1)
.L80127A1C:
/* BE11C 80127A1C 3C07F500 */  lui       $a3, 0xf500
/* BE120 80127A20 34E70100 */  ori       $a3, $a3, 0x100
/* BE124 80127A24 3C080703 */  lui       $t0, 0x703
/* BE128 80127A28 3508C000 */  ori       $t0, $t0, 0xc000
/* BE12C 80127A2C 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* BE130 80127A30 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* BE134 80127A34 0000802D */  daddu     $s0, $zero, $zero
/* BE138 80127A38 8C830000 */  lw        $v1, ($a0)
/* BE13C 80127A3C 3C02FD10 */  lui       $v0, 0xfd10
/* BE140 80127A40 0060302D */  daddu     $a2, $v1, $zero
/* BE144 80127A44 24630008 */  addiu     $v1, $v1, 8
/* BE148 80127A48 AC830000 */  sw        $v1, ($a0)
/* BE14C 80127A4C ACC20000 */  sw        $v0, ($a2)
/* BE150 80127A50 8FA200D8 */  lw        $v0, 0xd8($sp)
/* BE154 80127A54 3C05802F */  lui       $a1, %hi(D_802F4560)
/* BE158 80127A58 24A54560 */  addiu     $a1, $a1, %lo(D_802F4560)
/* BE15C 80127A5C 00021100 */  sll       $v0, $v0, 4
/* BE160 80127A60 00451021 */  addu      $v0, $v0, $a1
/* BE164 80127A64 ACC20004 */  sw        $v0, 4($a2)
/* BE168 80127A68 24620008 */  addiu     $v0, $v1, 8
/* BE16C 80127A6C AC820000 */  sw        $v0, ($a0)
/* BE170 80127A70 3C02E800 */  lui       $v0, 0xe800
/* BE174 80127A74 AC620000 */  sw        $v0, ($v1)
/* BE178 80127A78 24620010 */  addiu     $v0, $v1, 0x10
/* BE17C 80127A7C AC600004 */  sw        $zero, 4($v1)
/* BE180 80127A80 AC820000 */  sw        $v0, ($a0)
/* BE184 80127A84 3C020700 */  lui       $v0, 0x700
/* BE188 80127A88 AC62000C */  sw        $v0, 0xc($v1)
/* BE18C 80127A8C 24620018 */  addiu     $v0, $v1, 0x18
/* BE190 80127A90 AC670008 */  sw        $a3, 8($v1)
/* BE194 80127A94 AC820000 */  sw        $v0, ($a0)
/* BE198 80127A98 3C02E600 */  lui       $v0, 0xe600
/* BE19C 80127A9C AC620010 */  sw        $v0, 0x10($v1)
/* BE1A0 80127AA0 24620020 */  addiu     $v0, $v1, 0x20
/* BE1A4 80127AA4 AC600014 */  sw        $zero, 0x14($v1)
/* BE1A8 80127AA8 AC820000 */  sw        $v0, ($a0)
/* BE1AC 80127AAC 3C02F000 */  lui       $v0, 0xf000
/* BE1B0 80127AB0 AC620018 */  sw        $v0, 0x18($v1)
/* BE1B4 80127AB4 24620028 */  addiu     $v0, $v1, 0x28
/* BE1B8 80127AB8 AC68001C */  sw        $t0, 0x1c($v1)
/* BE1BC 80127ABC AC820000 */  sw        $v0, ($a0)
/* BE1C0 80127AC0 3C02E700 */  lui       $v0, 0xe700
/* BE1C4 80127AC4 AC620020 */  sw        $v0, 0x20($v1)
/* BE1C8 80127AC8 1A600014 */  blez      $s3, .L80127B1C
/* BE1CC 80127ACC AC600024 */   sw       $zero, 0x24($v1)
/* BE1D0 80127AD0 27B20028 */  addiu     $s2, $sp, 0x28
/* BE1D4 80127AD4 27B10040 */  addiu     $s1, $sp, 0x40
.L80127AD8:
/* BE1D8 80127AD8 8E260000 */  lw        $a2, ($s1)
/* BE1DC 80127ADC 24C2FFFF */  addiu     $v0, $a2, -1
/* BE1E0 80127AE0 2C42013F */  sltiu     $v0, $v0, 0x13f
/* BE1E4 80127AE4 5040000A */  beql      $v0, $zero, .L80127B10
/* BE1E8 80127AE8 26100001 */   addiu    $s0, $s0, 1
/* BE1EC 80127AEC 02501021 */  addu      $v0, $s2, $s0
/* BE1F0 80127AF0 90420000 */  lbu       $v0, ($v0)
/* BE1F4 80127AF4 00570018 */  mult      $v0, $s7
/* BE1F8 80127AF8 02A0282D */  daddu     $a1, $s5, $zero
/* BE1FC 80127AFC 0280382D */  daddu     $a3, $s4, $zero
/* BE200 80127B00 00005012 */  mflo      $t2
/* BE204 80127B04 0C049D30 */  jal       draw_digit
/* BE208 80127B08 03CA2021 */   addu     $a0, $fp, $t2
/* BE20C 80127B0C 26100001 */  addiu     $s0, $s0, 1
.L80127B10:
/* BE210 80127B10 0213102A */  slt       $v0, $s0, $s3
/* BE214 80127B14 1440FFF0 */  bnez      $v0, .L80127AD8
/* BE218 80127B18 26310004 */   addiu    $s1, $s1, 4
.L80127B1C:
/* BE21C 80127B1C 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* BE220 80127B20 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* BE224 80127B24 8C620000 */  lw        $v0, ($v1)
/* BE228 80127B28 0040202D */  daddu     $a0, $v0, $zero
/* BE22C 80127B2C 24420008 */  addiu     $v0, $v0, 8
/* BE230 80127B30 AC620000 */  sw        $v0, ($v1)
/* BE234 80127B34 3C02E700 */  lui       $v0, 0xe700
/* BE238 80127B38 AC820000 */  sw        $v0, ($a0)
/* BE23C 80127B3C AC800004 */  sw        $zero, 4($a0)
.L80127B40:
/* BE240 80127B40 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* BE244 80127B44 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* BE248 80127B48 8FB700BC */  lw        $s7, 0xbc($sp)
/* BE24C 80127B4C 8FB600B8 */  lw        $s6, 0xb8($sp)
/* BE250 80127B50 8FB500B4 */  lw        $s5, 0xb4($sp)
/* BE254 80127B54 8FB400B0 */  lw        $s4, 0xb0($sp)
/* BE258 80127B58 8FB300AC */  lw        $s3, 0xac($sp)
/* BE25C 80127B5C 8FB200A8 */  lw        $s2, 0xa8($sp)
/* BE260 80127B60 8FB100A4 */  lw        $s1, 0xa4($sp)
/* BE264 80127B64 8FB000A0 */  lw        $s0, 0xa0($sp)
/* BE268 80127B68 03E00008 */  jr        $ra
/* BE26C 80127B6C 27BD00C8 */   addiu    $sp, $sp, 0xc8
