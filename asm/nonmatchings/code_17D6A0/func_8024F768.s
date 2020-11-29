.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024F768
/* 17E048 8024F768 8C870044 */  lw        $a3, 0x44($a0)
/* 17E04C 8024F76C 28E2000B */  slti      $v0, $a3, 0xb
/* 17E050 8024F770 50400001 */  beql      $v0, $zero, .L8024F778
/* 17E054 8024F774 2407000A */   addiu    $a3, $zero, 0xa
.L8024F778:
/* 17E058 8024F778 3C056666 */  lui       $a1, 0x6666
/* 17E05C 8024F77C 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 17E060 8024F780 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 17E064 8024F784 34A56667 */  ori       $a1, $a1, 0x6667
/* 17E068 8024F788 00071A00 */  sll       $v1, $a3, 8
/* 17E06C 8024F78C 00671823 */  subu      $v1, $v1, $a3
/* 17E070 8024F790 00650018 */  mult      $v1, $a1
/* 17E074 8024F794 8C820000 */  lw        $v0, ($a0)
/* 17E078 8024F798 00031FC3 */  sra       $v1, $v1, 0x1f
/* 17E07C 8024F79C 0040302D */  daddu     $a2, $v0, $zero
/* 17E080 8024F7A0 24420008 */  addiu     $v0, $v0, 8
/* 17E084 8024F7A4 AC820000 */  sw        $v0, ($a0)
/* 17E088 8024F7A8 3C02FA00 */  lui       $v0, 0xfa00
/* 17E08C 8024F7AC ACC20000 */  sw        $v0, ($a2)
/* 17E090 8024F7B0 00004010 */  mfhi      $t0
/* 17E094 8024F7B4 00081083 */  sra       $v0, $t0, 2
/* 17E098 8024F7B8 00431023 */  subu      $v0, $v0, $v1
/* 17E09C 8024F7BC 304200FF */  andi      $v0, $v0, 0xff
/* 17E0A0 8024F7C0 03E00008 */  jr        $ra
/* 17E0A4 8024F7C4 ACC20004 */   sw       $v0, 4($a2)
