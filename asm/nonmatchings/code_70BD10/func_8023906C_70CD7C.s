.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023906C_70CD7C
/* 70CD7C 8023906C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 70CD80 80239070 AFB3001C */  sw        $s3, 0x1c($sp)
/* 70CD84 80239074 0080982D */  daddu     $s3, $a0, $zero
/* 70CD88 80239078 3C06800E */  lui       $a2, %hi(gBattleStatus)
/* 70CD8C 8023907C 24C6C070 */  addiu     $a2, $a2, %lo(gBattleStatus)
/* 70CD90 80239080 AFBF0024 */  sw        $ra, 0x24($sp)
/* 70CD94 80239084 AFB40020 */  sw        $s4, 0x20($sp)
/* 70CD98 80239088 AFB20018 */  sw        $s2, 0x18($sp)
/* 70CD9C 8023908C AFB10014 */  sw        $s1, 0x14($sp)
/* 70CDA0 80239090 AFB00010 */  sw        $s0, 0x10($sp)
/* 70CDA4 80239094 8CC400DC */  lw        $a0, 0xdc($a2)
/* 70CDA8 80239098 80820425 */  lb        $v0, 0x425($a0)
/* 70CDAC 8023909C 3C038024 */  lui       $v1, %hi(D_8023D2D0)
/* 70CDB0 802390A0 2463D2D0 */  addiu     $v1, $v1, %lo(D_8023D2D0)
/* 70CDB4 802390A4 00821021 */  addu      $v0, $a0, $v0
/* 70CDB8 802390A8 8045040D */  lb        $a1, 0x40d($v0)
/* 70CDBC 802390AC 00051080 */  sll       $v0, $a1, 2
/* 70CDC0 802390B0 00438021 */  addu      $s0, $v0, $v1
/* 70CDC4 802390B4 00451021 */  addu      $v0, $v0, $a1
/* 70CDC8 802390B8 00021080 */  sll       $v0, $v0, 2
/* 70CDCC 802390BC 2442022C */  addiu     $v0, $v0, 0x22c
/* 70CDD0 802390C0 8E030000 */  lw        $v1, ($s0)
/* 70CDD4 802390C4 00828821 */  addu      $s1, $a0, $v0
/* 70CDD8 802390C8 AE630084 */  sw        $v1, 0x84($s3)
/* 70CDDC 802390CC 8E020000 */  lw        $v0, ($s0)
/* 70CDE0 802390D0 2412FFFF */  addiu     $s2, $zero, -1
/* 70CDE4 802390D4 10520011 */  beq       $v0, $s2, .L8023911C
/* 70CDE8 802390D8 00C0A02D */   daddu    $s4, $a2, $zero
/* 70CDEC 802390DC 10400010 */  beqz      $v0, .L80239120
/* 70CDF0 802390E0 24020002 */   addiu    $v0, $zero, 2
/* 70CDF4 802390E4 86240000 */  lh        $a0, ($s1)
/* 70CDF8 802390E8 0C09A75B */  jal       get_actor
/* 70CDFC 802390EC 00000000 */   nop      
/* 70CE00 802390F0 0C00A67F */  jal       rand_int
/* 70CE04 802390F4 24040063 */   addiu    $a0, $zero, 0x63
/* 70CE08 802390F8 82830081 */  lb        $v1, 0x81($s4)
/* 70CE0C 802390FC 0043102A */  slt       $v0, $v0, $v1
/* 70CE10 80239100 50400005 */  beql      $v0, $zero, .L80239118
/* 70CE14 80239104 AE000000 */   sw       $zero, ($s0)
/* 70CE18 80239108 AE120000 */  sw        $s2, ($s0)
/* 70CE1C 8023910C 86220000 */  lh        $v0, ($s1)
/* 70CE20 80239110 0808E447 */  j         .L8023911C
/* 70CE24 80239114 AE620084 */   sw       $v0, 0x84($s3)
.L80239118:
/* 70CE28 80239118 AE600084 */  sw        $zero, 0x84($s3)
.L8023911C:
/* 70CE2C 8023911C 24020002 */  addiu     $v0, $zero, 2
.L80239120:
/* 70CE30 80239120 8FBF0024 */  lw        $ra, 0x24($sp)
/* 70CE34 80239124 8FB40020 */  lw        $s4, 0x20($sp)
/* 70CE38 80239128 8FB3001C */  lw        $s3, 0x1c($sp)
/* 70CE3C 8023912C 8FB20018 */  lw        $s2, 0x18($sp)
/* 70CE40 80239130 8FB10014 */  lw        $s1, 0x14($sp)
/* 70CE44 80239134 8FB00010 */  lw        $s0, 0x10($sp)
/* 70CE48 80239138 03E00008 */  jr        $ra
/* 70CE4C 8023913C 27BD0028 */   addiu    $sp, $sp, 0x28
