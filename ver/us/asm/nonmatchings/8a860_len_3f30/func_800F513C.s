.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F513C
/* 8E5EC 800F513C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8E5F0 800F5140 AFB00010 */  sw        $s0, 0x10($sp)
/* 8E5F4 800F5144 3C108011 */  lui       $s0, %hi(D_8010D69C)
/* 8E5F8 800F5148 2610D69C */  addiu     $s0, $s0, %lo(D_8010D69C)
/* 8E5FC 800F514C AFBF0014 */  sw        $ra, 0x14($sp)
/* 8E600 800F5150 AE040000 */  sw        $a0, ($s0)
/* 8E604 800F5154 90820323 */  lbu       $v0, 0x323($a0)
/* 8E608 800F5158 A480032C */  sh        $zero, 0x32c($a0)
/* 8E60C 800F515C 3C018011 */  lui       $at, %hi(D_8010D693)
/* 8E610 800F5160 A022D693 */  sb        $v0, %lo(D_8010D693)($at)
/* 8E614 800F5164 0C03A635 */  jal       func_800E98D4
/* 8E618 800F5168 00000000 */   nop
/* 8E61C 800F516C 3C048011 */  lui       $a0, %hi(D_8010D699)
/* 8E620 800F5170 2484D699 */  addiu     $a0, $a0, %lo(D_8010D699)
/* 8E624 800F5174 3C018011 */  lui       $at, %hi(D_8010D69A)
/* 8E628 800F5178 A022D69A */  sb        $v0, %lo(D_8010D69A)($at)
/* 8E62C 800F517C A0800000 */  sb        $zero, ($a0)
/* 8E630 800F5180 8E100000 */  lw        $s0, ($s0)
/* 8E634 800F5184 3C068011 */  lui       $a2, %hi(D_8010D698)
/* 8E638 800F5188 24C6D698 */  addiu     $a2, $a2, %lo(D_8010D698)
/* 8E63C 800F518C 8E030318 */  lw        $v1, 0x318($s0)
/* 8E640 800F5190 24050001 */  addiu     $a1, $zero, 1
/* 8E644 800F5194 28620064 */  slti      $v0, $v1, 0x64
/* 8E648 800F5198 1440000C */  bnez      $v0, .L800F51CC
/* 8E64C 800F519C A0C50000 */   sb       $a1, ($a2)
/* 8E650 800F51A0 2462FF9C */  addiu     $v0, $v1, -0x64
/* 8E654 800F51A4 AE020318 */  sw        $v0, 0x318($s0)
/* 8E658 800F51A8 0040182D */  daddu     $v1, $v0, $zero
/* 8E65C 800F51AC 28620064 */  slti      $v0, $v1, 0x64
/* 8E660 800F51B0 14400005 */  bnez      $v0, .L800F51C8
/* 8E664 800F51B4 A0850000 */   sb       $a1, ($a0)
/* 8E668 800F51B8 2462FF9C */  addiu     $v0, $v1, -0x64
/* 8E66C 800F51BC AE020318 */  sw        $v0, 0x318($s0)
/* 8E670 800F51C0 24020002 */  addiu     $v0, $zero, 2
/* 8E674 800F51C4 A0820000 */  sb        $v0, ($a0)
.L800F51C8:
/* 8E678 800F51C8 A0C00000 */  sb        $zero, ($a2)
.L800F51CC:
/* 8E67C 800F51CC 3C058011 */  lui       $a1, %hi(D_8010D69C)
/* 8E680 800F51D0 8CA5D69C */  lw        $a1, %lo(D_8010D69C)($a1)
/* 8E684 800F51D4 24020006 */  addiu     $v0, $zero, 6
/* 8E688 800F51D8 3C018011 */  lui       $at, %hi(D_8010D68F)
/* 8E68C 800F51DC A022D68F */  sb        $v0, %lo(D_8010D68F)($at)
/* 8E690 800F51E0 8CA20328 */  lw        $v0, 0x328($a1)
/* 8E694 800F51E4 8CA40324 */  lw        $a0, 0x324($a1)
/* 8E698 800F51E8 3C038011 */  lui       $v1, %hi(D_8010D648)
/* 8E69C 800F51EC 2463D648 */  addiu     $v1, $v1, %lo(D_8010D648)
/* 8E6A0 800F51F0 3C018011 */  lui       $at, %hi(D_8010D68E)
/* 8E6A4 800F51F4 A020D68E */  sb        $zero, %lo(D_8010D68E)($at)
/* 8E6A8 800F51F8 3C018011 */  lui       $at, %hi(D_8010D640)
/* 8E6AC 800F51FC AC20D640 */  sw        $zero, %lo(D_8010D640)($at)
/* 8E6B0 800F5200 AC620000 */  sw        $v0, ($v1)
/* 8E6B4 800F5204 0044102A */  slt       $v0, $v0, $a0
/* 8E6B8 800F5208 14400002 */  bnez      $v0, .L800F5214
/* 8E6BC 800F520C 2482FFFF */   addiu    $v0, $a0, -1
/* 8E6C0 800F5210 AC620000 */  sw        $v0, ($v1)
.L800F5214:
/* 8E6C4 800F5214 8C620000 */  lw        $v0, ($v1)
/* 8E6C8 800F5218 3C048011 */  lui       $a0, %hi(D_8010D656)
/* 8E6CC 800F521C 2484D656 */  addiu     $a0, $a0, %lo(D_8010D656)
/* 8E6D0 800F5220 3C018011 */  lui       $at, %hi(D_8010D654)
/* 8E6D4 800F5224 A020D654 */  sb        $zero, %lo(D_8010D654)($at)
/* 8E6D8 800F5228 3C018011 */  lui       $at, %hi(D_8010D64C)
/* 8E6DC 800F522C AC22D64C */  sw        $v0, %lo(D_8010D64C)($at)
/* 8E6E0 800F5230 90A20327 */  lbu       $v0, 0x327($a1)
/* 8E6E4 800F5234 24030006 */  addiu     $v1, $zero, 6
/* 8E6E8 800F5238 A0820000 */  sb        $v0, ($a0)
/* 8E6EC 800F523C 00021600 */  sll       $v0, $v0, 0x18
/* 8E6F0 800F5240 00021603 */  sra       $v0, $v0, 0x18
/* 8E6F4 800F5244 0062102A */  slt       $v0, $v1, $v0
/* 8E6F8 800F5248 54400001 */  bnel      $v0, $zero, .L800F5250
/* 8E6FC 800F524C A0830000 */   sb       $v1, ($a0)
.L800F5250:
/* 8E700 800F5250 8CA20324 */  lw        $v0, 0x324($a1)
/* 8E704 800F5254 3C048011 */  lui       $a0, %hi(D_8010D655)
/* 8E708 800F5258 2484D655 */  addiu     $a0, $a0, %lo(D_8010D655)
/* 8E70C 800F525C 28420006 */  slti      $v0, $v0, 6
/* 8E710 800F5260 10400003 */  beqz      $v0, .L800F5270
/* 8E714 800F5264 A0830000 */   sb       $v1, ($a0)
/* 8E718 800F5268 90A20327 */  lbu       $v0, 0x327($a1)
/* 8E71C 800F526C A0820000 */  sb        $v0, ($a0)
.L800F5270:
/* 8E720 800F5270 240200FF */  addiu     $v0, $zero, 0xff
/* 8E724 800F5274 3C018011 */  lui       $at, %hi(D_8010D650)
/* 8E728 800F5278 AC22D650 */  sw        $v0, %lo(D_8010D650)($at)
/* 8E72C 800F527C 24020009 */  addiu     $v0, $zero, 9
/* 8E730 800F5280 3C018011 */  lui       $at, %hi(D_8010D691)
/* 8E734 800F5284 A022D691 */  sb        $v0, %lo(D_8010D691)($at)
/* 8E738 800F5288 24020002 */  addiu     $v0, $zero, 2
/* 8E73C 800F528C 3C04800F */  lui       $a0, %hi(popup_menu_update)
/* 8E740 800F5290 24841A10 */  addiu     $a0, $a0, %lo(popup_menu_update)
/* 8E744 800F5294 3C018011 */  lui       $at, %hi(D_8010D692)
/* 8E748 800F5298 A022D692 */  sb        $v0, %lo(D_8010D692)($at)
/* 8E74C 800F529C 0C048C8F */  jal       create_generic_entity_frontUI
/* 8E750 800F52A0 0000282D */   daddu    $a1, $zero, $zero
/* 8E754 800F52A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8E758 800F52A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8E75C 800F52AC 3C018011 */  lui       $at, %hi(D_8010D694)
/* 8E760 800F52B0 AC22D694 */  sw        $v0, %lo(D_8010D694)($at)
/* 8E764 800F52B4 03E00008 */  jr        $ra
/* 8E768 800F52B8 27BD0018 */   addiu    $sp, $sp, 0x18
