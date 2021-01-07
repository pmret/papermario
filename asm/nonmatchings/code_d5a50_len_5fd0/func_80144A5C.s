.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80144A5C
/* DB15C 80144A5C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DB160 80144A60 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DB164 80144A64 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB168 80144A68 AFBF0014 */  sw        $ra, 0x14($sp)
/* DB16C 80144A6C AFB00010 */  sw        $s0, 0x10($sp)
/* DB170 80144A70 80420070 */  lb        $v0, 0x70($v0)
/* DB174 80144A74 14400030 */  bnez      $v0, .L80144B38
/* DB178 80144A78 00000000 */   nop      
/* DB17C 80144A7C 3C108015 */  lui       $s0, %hi(D_80151314)
/* DB180 80144A80 26101314 */  addiu     $s0, $s0, %lo(D_80151314)
/* DB184 80144A84 0C00AB4B */  jal       heap_free
/* DB188 80144A88 8E040000 */   lw       $a0, ($s0)
/* DB18C 80144A8C 3C048015 */  lui       $a0, %hi(D_8014EFC4)
/* DB190 80144A90 0C00AB39 */  jal       heap_malloc
/* DB194 80144A94 8C84EFC4 */   lw       $a0, %lo(D_8014EFC4)($a0)
/* DB198 80144A98 14400003 */  bnez      $v0, .L80144AA8
/* DB19C 80144A9C AE020000 */   sw       $v0, ($s0)
.L80144AA0:
/* DB1A0 80144AA0 080512A8 */  j         .L80144AA0
/* DB1A4 80144AA4 00000000 */   nop      
.L80144AA8:
/* DB1A8 80144AA8 0000482D */  daddu     $t1, $zero, $zero
/* DB1AC 80144AAC 240AFFFF */  addiu     $t2, $zero, -1
/* DB1B0 80144AB0 3C028015 */  lui       $v0, %hi(D_80157F70)
/* DB1B4 80144AB4 24427F70 */  addiu     $v0, $v0, %lo(D_80157F70)
/* DB1B8 80144AB8 0040402D */  daddu     $t0, $v0, $zero
/* DB1BC 80144ABC 3C028015 */  lui       $v0, %hi(D_80157970)
/* DB1C0 80144AC0 24427970 */  addiu     $v0, $v0, %lo(D_80157970)
/* DB1C4 80144AC4 0040382D */  daddu     $a3, $v0, $zero
/* DB1C8 80144AC8 3C068015 */  lui       $a2, %hi(D_80151314)
/* DB1CC 80144ACC 24C61314 */  addiu     $a2, $a2, %lo(D_80151314)
/* DB1D0 80144AD0 3C058015 */  lui       $a1, %hi(D_8015133C)
/* DB1D4 80144AD4 24A5133C */  addiu     $a1, $a1, %lo(D_8015133C)
/* DB1D8 80144AD8 8CC30000 */  lw        $v1, ($a2)
/* DB1DC 80144ADC 8CA40000 */  lw        $a0, ($a1)
/* DB1E0 80144AE0 3C028015 */  lui       $v0, %hi(D_80157964)
/* DB1E4 80144AE4 24427964 */  addiu     $v0, $v0, %lo(D_80157964)
/* DB1E8 80144AE8 AC430000 */  sw        $v1, ($v0)
/* DB1EC 80144AEC AC800000 */  sw        $zero, ($a0)
/* DB1F0 80144AF0 8C430000 */  lw        $v1, ($v0)
/* DB1F4 80144AF4 3C028015 */  lui       $v0, %hi(D_80157968)
/* DB1F8 80144AF8 24427968 */  addiu     $v0, $v0, %lo(D_80157968)
/* DB1FC 80144AFC ACA20000 */  sw        $v0, ($a1)
/* DB200 80144B00 3C018015 */  lui       $at, %hi(D_801512C8)
/* DB204 80144B04 AC2712C8 */  sw        $a3, %lo(D_801512C8)($at)
/* DB208 80144B08 3C018015 */  lui       $at, %hi(D_801512D0)
/* DB20C 80144B0C AC2812D0 */  sw        $t0, %lo(D_801512D0)($at)
/* DB210 80144B10 ACC30000 */  sw        $v1, ($a2)
.L80144B14:
/* DB214 80144B14 ACEA0000 */  sw        $t2, ($a3)
/* DB218 80144B18 AD0A0000 */  sw        $t2, ($t0)
/* DB21C 80144B1C 25080008 */  addiu     $t0, $t0, 8
/* DB220 80144B20 25290001 */  addiu     $t1, $t1, 1
/* DB224 80144B24 292200C0 */  slti      $v0, $t1, 0xc0
/* DB228 80144B28 1440FFFA */  bnez      $v0, .L80144B14
/* DB22C 80144B2C 24E70008 */   addiu    $a3, $a3, 8
/* DB230 80144B30 08051304 */  j         .L80144C10
/* DB234 80144B34 00000000 */   nop      
.L80144B38:
/* DB238 80144B38 3C028015 */  lui       $v0, %hi(D_8014EFC0)
/* DB23C 80144B3C 8C42EFC0 */  lw        $v0, %lo(D_8014EFC0)($v0)
/* DB240 80144B40 1440000F */  bnez      $v0, .L80144B80
/* DB244 80144B44 00000000 */   nop      
/* DB248 80144B48 3C108015 */  lui       $s0, %hi(D_80151314)
/* DB24C 80144B4C 26101314 */  addiu     $s0, $s0, %lo(D_80151314)
/* DB250 80144B50 0C00AB4B */  jal       heap_free
/* DB254 80144B54 8E040000 */   lw       $a0, ($s0)
/* DB258 80144B58 3C048015 */  lui       $a0, %hi(D_8014EFC4)
/* DB25C 80144B5C 8C84EFC4 */  lw        $a0, %lo(D_8014EFC4)($a0)
/* DB260 80144B60 000417C2 */  srl       $v0, $a0, 0x1f
/* DB264 80144B64 00822021 */  addu      $a0, $a0, $v0
/* DB268 80144B68 0C00AB39 */  jal       heap_malloc
/* DB26C 80144B6C 00042043 */   sra      $a0, $a0, 1
/* DB270 80144B70 14400005 */  bnez      $v0, .L80144B88
/* DB274 80144B74 AE020000 */   sw       $v0, ($s0)
.L80144B78:
/* DB278 80144B78 080512DE */  j         .L80144B78
/* DB27C 80144B7C 00000000 */   nop      
.L80144B80:
/* DB280 80144B80 3C018015 */  lui       $at, %hi(D_80151314)
/* DB284 80144B84 AC221314 */  sw        $v0, %lo(D_80151314)($at)
.L80144B88:
/* DB288 80144B88 0000482D */  daddu     $t1, $zero, $zero
/* DB28C 80144B8C 240AFFFF */  addiu     $t2, $zero, -1
/* DB290 80144B90 3C028016 */  lui       $v0, %hi(D_80158B80)
/* DB294 80144B94 24428B80 */  addiu     $v0, $v0, %lo(D_80158B80)
/* DB298 80144B98 0040402D */  daddu     $t0, $v0, $zero
/* DB29C 80144B9C 3C028016 */  lui       $v0, %hi(D_80158580)
/* DB2A0 80144BA0 24428580 */  addiu     $v0, $v0, %lo(D_80158580)
/* DB2A4 80144BA4 0040382D */  daddu     $a3, $v0, $zero
/* DB2A8 80144BA8 3C068015 */  lui       $a2, %hi(D_80151314)
/* DB2AC 80144BAC 24C61314 */  addiu     $a2, $a2, %lo(D_80151314)
/* DB2B0 80144BB0 3C058015 */  lui       $a1, %hi(D_8015133C)
/* DB2B4 80144BB4 24A5133C */  addiu     $a1, $a1, %lo(D_8015133C)
/* DB2B8 80144BB8 8CC30000 */  lw        $v1, ($a2)
/* DB2BC 80144BBC 8CA40000 */  lw        $a0, ($a1)
/* DB2C0 80144BC0 3C028016 */  lui       $v0, %hi(D_80158570)
/* DB2C4 80144BC4 24428570 */  addiu     $v0, $v0, %lo(D_80158570)
/* DB2C8 80144BC8 AC430000 */  sw        $v1, ($v0)
/* DB2CC 80144BCC AC800000 */  sw        $zero, ($a0)
/* DB2D0 80144BD0 8C430000 */  lw        $v1, ($v0)
/* DB2D4 80144BD4 3C028016 */  lui       $v0, %hi(D_80158574)
/* DB2D8 80144BD8 24428574 */  addiu     $v0, $v0, %lo(D_80158574)
/* DB2DC 80144BDC ACA20000 */  sw        $v0, ($a1)
/* DB2E0 80144BE0 3C018015 */  lui       $at, %hi(D_801512C8)
/* DB2E4 80144BE4 AC2712C8 */  sw        $a3, %lo(D_801512C8)($at)
/* DB2E8 80144BE8 3C018015 */  lui       $at, %hi(D_801512D0)
/* DB2EC 80144BEC AC2812D0 */  sw        $t0, %lo(D_801512D0)($at)
/* DB2F0 80144BF0 ACC30000 */  sw        $v1, ($a2)
.L80144BF4:
/* DB2F4 80144BF4 ACEA0000 */  sw        $t2, ($a3)
/* DB2F8 80144BF8 AD0A0000 */  sw        $t2, ($t0)
/* DB2FC 80144BFC 25080008 */  addiu     $t0, $t0, 8
/* DB300 80144C00 25290001 */  addiu     $t1, $t1, 1
/* DB304 80144C04 292200C0 */  slti      $v0, $t1, 0xc0
/* DB308 80144C08 1440FFFA */  bnez      $v0, .L80144BF4
/* DB30C 80144C0C 24E70008 */   addiu    $a3, $a3, 8
.L80144C10:
/* DB310 80144C10 8FBF0014 */  lw        $ra, 0x14($sp)
/* DB314 80144C14 8FB00010 */  lw        $s0, 0x10($sp)
/* DB318 80144C18 03E00008 */  jr        $ra
/* DB31C 80144C1C 27BD0018 */   addiu    $sp, $sp, 0x18
