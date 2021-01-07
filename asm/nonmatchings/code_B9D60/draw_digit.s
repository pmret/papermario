.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_digit
/* BDBC0 801274C0 3C0A800A */  lui       $t2, %hi(D_8009A66C)
/* BDBC4 801274C4 254AA66C */  addiu     $t2, $t2, %lo(D_8009A66C)
/* BDBC8 801274C8 3C028015 */  lui       $v0, %hi(D_8014C340)
/* BDBCC 801274CC 2442C340 */  addiu     $v0, $v0, %lo(D_8014C340)
/* BDBD0 801274D0 00054880 */  sll       $t1, $a1, 2
/* BDBD4 801274D4 01254821 */  addu      $t1, $t1, $a1
/* BDBD8 801274D8 00094880 */  sll       $t1, $t1, 2
/* BDBDC 801274DC 01224821 */  addu      $t1, $t1, $v0
/* BDBE0 801274E0 8D480000 */  lw        $t0, ($t2)
/* BDBE4 801274E4 3C050700 */  lui       $a1, 0x700
/* BDBE8 801274E8 0100582D */  daddu     $t3, $t0, $zero
/* BDBEC 801274EC 25080008 */  addiu     $t0, $t0, 8
/* BDBF0 801274F0 AD480000 */  sw        $t0, ($t2)
/* BDBF4 801274F4 91220005 */  lbu       $v0, 5($t1)
/* BDBF8 801274F8 25030008 */  addiu     $v1, $t0, 8
/* BDBFC 801274FC AD640004 */  sw        $a0, 4($t3)
/* BDC00 80127500 AD430000 */  sw        $v1, ($t2)
/* BDC04 80127504 3C03FD48 */  lui       $v1, 0xfd48
/* BDC08 80127508 00021042 */  srl       $v0, $v0, 1
/* BDC0C 8012750C 2442FFFF */  addiu     $v0, $v0, -1
/* BDC10 80127510 30420FFF */  andi      $v0, $v0, 0xfff
/* BDC14 80127514 00431025 */  or        $v0, $v0, $v1
/* BDC18 80127518 AD620000 */  sw        $v0, ($t3)
/* BDC1C 8012751C 91220005 */  lbu       $v0, 5($t1)
/* BDC20 80127520 25030010 */  addiu     $v1, $t0, 0x10
/* BDC24 80127524 AD050004 */  sw        $a1, 4($t0)
/* BDC28 80127528 AD430000 */  sw        $v1, ($t2)
/* BDC2C 8012752C 3C03E600 */  lui       $v1, 0xe600
/* BDC30 80127530 AD030008 */  sw        $v1, 8($t0)
/* BDC34 80127534 25030018 */  addiu     $v1, $t0, 0x18
/* BDC38 80127538 AD00000C */  sw        $zero, 0xc($t0)
/* BDC3C 8012753C AD430000 */  sw        $v1, ($t2)
/* BDC40 80127540 3C03F400 */  lui       $v1, 0xf400
/* BDC44 80127544 AD030010 */  sw        $v1, 0x10($t0)
/* BDC48 80127548 3C03F548 */  lui       $v1, 0xf548
/* BDC4C 8012754C 00021042 */  srl       $v0, $v0, 1
/* BDC50 80127550 24420007 */  addiu     $v0, $v0, 7
/* BDC54 80127554 000210C2 */  srl       $v0, $v0, 3
/* BDC58 80127558 00021240 */  sll       $v0, $v0, 9
/* BDC5C 8012755C 00431025 */  or        $v0, $v0, $v1
/* BDC60 80127560 AD020000 */  sw        $v0, ($t0)
/* BDC64 80127564 91220005 */  lbu       $v0, 5($t1)
/* BDC68 80127568 91240006 */  lbu       $a0, 6($t1)
/* BDC6C 8012756C 25030020 */  addiu     $v1, $t0, 0x20
/* BDC70 80127570 AD430000 */  sw        $v1, ($t2)
/* BDC74 80127574 3C03E700 */  lui       $v1, 0xe700
/* BDC78 80127578 AD030018 */  sw        $v1, 0x18($t0)
/* BDC7C 8012757C 25030028 */  addiu     $v1, $t0, 0x28
/* BDC80 80127580 AD00001C */  sw        $zero, 0x1c($t0)
/* BDC84 80127584 AD430000 */  sw        $v1, ($t2)
/* BDC88 80127588 25030030 */  addiu     $v1, $t0, 0x30
/* BDC8C 8012758C 2442FFFF */  addiu     $v0, $v0, -1
/* BDC90 80127590 00021040 */  sll       $v0, $v0, 1
/* BDC94 80127594 30420FFF */  andi      $v0, $v0, 0xfff
/* BDC98 80127598 00021300 */  sll       $v0, $v0, 0xc
/* BDC9C 8012759C 2484FFFF */  addiu     $a0, $a0, -1
/* BDCA0 801275A0 00042080 */  sll       $a0, $a0, 2
/* BDCA4 801275A4 30840FFF */  andi      $a0, $a0, 0xfff
/* BDCA8 801275A8 00852025 */  or        $a0, $a0, $a1
/* BDCAC 801275AC 00441025 */  or        $v0, $v0, $a0
/* BDCB0 801275B0 AD020014 */  sw        $v0, 0x14($t0)
/* BDCB4 801275B4 91220005 */  lbu       $v0, 5($t1)
/* BDCB8 801275B8 3C050400 */  lui       $a1, 0x400
/* BDCBC 801275BC AD000024 */  sw        $zero, 0x24($t0)
/* BDCC0 801275C0 AD430000 */  sw        $v1, ($t2)
/* BDCC4 801275C4 3C03F200 */  lui       $v1, 0xf200
/* BDCC8 801275C8 AD030028 */  sw        $v1, 0x28($t0)
/* BDCCC 801275CC 3C03F540 */  lui       $v1, 0xf540
/* BDCD0 801275D0 25040038 */  addiu     $a0, $t0, 0x38
/* BDCD4 801275D4 00021042 */  srl       $v0, $v0, 1
/* BDCD8 801275D8 24420007 */  addiu     $v0, $v0, 7
/* BDCDC 801275DC 000210C2 */  srl       $v0, $v0, 3
/* BDCE0 801275E0 00021240 */  sll       $v0, $v0, 9
/* BDCE4 801275E4 00431025 */  or        $v0, $v0, $v1
/* BDCE8 801275E8 AD020020 */  sw        $v0, 0x20($t0)
/* BDCEC 801275EC 91220005 */  lbu       $v0, 5($t1)
/* BDCF0 801275F0 91230006 */  lbu       $v1, 6($t1)
/* BDCF4 801275F4 34A50400 */  ori       $a1, $a1, 0x400
/* BDCF8 801275F8 AD440000 */  sw        $a0, ($t2)
/* BDCFC 801275FC 3C04E400 */  lui       $a0, 0xe400
/* BDD00 80127600 2442FFFF */  addiu     $v0, $v0, -1
/* BDD04 80127604 00021080 */  sll       $v0, $v0, 2
/* BDD08 80127608 30420FFF */  andi      $v0, $v0, 0xfff
/* BDD0C 8012760C 00021300 */  sll       $v0, $v0, 0xc
/* BDD10 80127610 2463FFFF */  addiu     $v1, $v1, -1
/* BDD14 80127614 00031880 */  sll       $v1, $v1, 2
/* BDD18 80127618 30630FFF */  andi      $v1, $v1, 0xfff
/* BDD1C 8012761C 00431025 */  or        $v0, $v0, $v1
/* BDD20 80127620 AD02002C */  sw        $v0, 0x2c($t0)
/* BDD24 80127624 91230005 */  lbu       $v1, 5($t1)
/* BDD28 80127628 91220006 */  lbu       $v0, 6($t1)
/* BDD2C 8012762C 00C31821 */  addu      $v1, $a2, $v1
/* BDD30 80127630 00031880 */  sll       $v1, $v1, 2
/* BDD34 80127634 30630FFF */  andi      $v1, $v1, 0xfff
/* BDD38 80127638 00031B00 */  sll       $v1, $v1, 0xc
/* BDD3C 8012763C 00E21021 */  addu      $v0, $a3, $v0
/* BDD40 80127640 00021080 */  sll       $v0, $v0, 2
/* BDD44 80127644 30420FFF */  andi      $v0, $v0, 0xfff
/* BDD48 80127648 00441025 */  or        $v0, $v0, $a0
/* BDD4C 8012764C 00621825 */  or        $v1, $v1, $v0
/* BDD50 80127650 00063080 */  sll       $a2, $a2, 2
/* BDD54 80127654 30C60FFF */  andi      $a2, $a2, 0xfff
/* BDD58 80127658 00063300 */  sll       $a2, $a2, 0xc
/* BDD5C 8012765C 00073880 */  sll       $a3, $a3, 2
/* BDD60 80127660 30E70FFF */  andi      $a3, $a3, 0xfff
/* BDD64 80127664 00C73025 */  or        $a2, $a2, $a3
/* BDD68 80127668 25020040 */  addiu     $v0, $t0, 0x40
/* BDD6C 8012766C AD030030 */  sw        $v1, 0x30($t0)
/* BDD70 80127670 AD060034 */  sw        $a2, 0x34($t0)
/* BDD74 80127674 AD420000 */  sw        $v0, ($t2)
/* BDD78 80127678 3C02E100 */  lui       $v0, 0xe100
/* BDD7C 8012767C AD020038 */  sw        $v0, 0x38($t0)
/* BDD80 80127680 25020048 */  addiu     $v0, $t0, 0x48
/* BDD84 80127684 AD00003C */  sw        $zero, 0x3c($t0)
/* BDD88 80127688 AD420000 */  sw        $v0, ($t2)
/* BDD8C 8012768C 3C02F100 */  lui       $v0, 0xf100
/* BDD90 80127690 AD020040 */  sw        $v0, 0x40($t0)
/* BDD94 80127694 03E00008 */  jr        $ra
/* BDD98 80127698 AD050044 */   sw       $a1, 0x44($t0)
