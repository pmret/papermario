.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240664_CF81D4
/* CF81D4 80240664 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF81D8 80240668 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF81DC 8024066C 8C82000C */  lw        $v0, 0xc($a0)
/* CF81E0 80240670 0C0B1EAF */  jal       get_variable
/* CF81E4 80240674 8C450000 */   lw       $a1, ($v0)
/* CF81E8 80240678 0040182D */  daddu     $v1, $v0, $zero
/* CF81EC 8024067C 10600012 */  beqz      $v1, .L802406C8
/* CF81F0 80240680 0000202D */   daddu    $a0, $zero, $zero
/* CF81F4 80240684 8C620000 */  lw        $v0, ($v1)
/* CF81F8 80240688 5040000A */  beql      $v0, $zero, .L802406B4
/* CF81FC 8024068C 00041080 */   sll      $v0, $a0, 2
/* CF8200 80240690 3C058025 */  lui       $a1, %hi(D_8024DD88)
/* CF8204 80240694 24A5DD88 */  addiu     $a1, $a1, %lo(D_8024DD88)
.L80240698:
/* CF8208 80240698 24630004 */  addiu     $v1, $v1, 4
/* CF820C 8024069C 24840001 */  addiu     $a0, $a0, 1
/* CF8210 802406A0 ACA20000 */  sw        $v0, ($a1)
/* CF8214 802406A4 8C620000 */  lw        $v0, ($v1)
/* CF8218 802406A8 1440FFFB */  bnez      $v0, .L80240698
/* CF821C 802406AC 24A50004 */   addiu    $a1, $a1, 4
/* CF8220 802406B0 00041080 */  sll       $v0, $a0, 2
.L802406B4:
/* CF8224 802406B4 3C018025 */  lui       $at, %hi(D_8024DD88)
/* CF8228 802406B8 00220821 */  addu      $at, $at, $v0
/* CF822C 802406BC AC20DD88 */  sw        $zero, %lo(D_8024DD88)($at)
/* CF8230 802406C0 080901BC */  j         .L802406F0
/* CF8234 802406C4 00000000 */   nop      
.L802406C8:
/* CF8238 802406C8 3C038025 */  lui       $v1, %hi(D_8024DD88)
/* CF823C 802406CC 2463DD88 */  addiu     $v1, $v1, %lo(D_8024DD88)
/* CF8240 802406D0 0060282D */  daddu     $a1, $v1, $zero
.L802406D4:
/* CF8244 802406D4 24820080 */  addiu     $v0, $a0, 0x80
/* CF8248 802406D8 AC620000 */  sw        $v0, ($v1)
/* CF824C 802406DC 24630004 */  addiu     $v1, $v1, 4
/* CF8250 802406E0 24840001 */  addiu     $a0, $a0, 1
/* CF8254 802406E4 2882005B */  slti      $v0, $a0, 0x5b
/* CF8258 802406E8 1440FFFA */  bnez      $v0, .L802406D4
/* CF825C 802406EC ACA0016C */   sw       $zero, 0x16c($a1)
.L802406F0:
/* CF8260 802406F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF8264 802406F4 24020002 */  addiu     $v0, $zero, 2
/* CF8268 802406F8 03E00008 */  jr        $ra
/* CF826C 802406FC 27BD0018 */   addiu    $sp, $sp, 0x18
